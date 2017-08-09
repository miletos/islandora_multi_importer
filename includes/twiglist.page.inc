<?php

/**
 * @file
 * Callbacks and functions for the Twig template listing Page.
 */

/**
 * Shows Twig template listing.
 *
 * Users can CRUD manage their templates. Heavily borrowed 
 * from XML forms listing.
 *
 * @return array
 *   The table to display.
 */
function islandora_multi_importer_twiglistpage_callback() {

  module_load_include('inc', 'islandora_multi_importer', 'includes/TwigTemplateDatabase');
  $twig_templates_from_db = TwigTemplateDatabase::GetIdsAndNames();

  // No forms exist can only create.
  if (count($twig_templates_from_db ) == 0) {
    return '<div>No Twig templagtes are defined. Please create a new form.</div><br/>';
  }

  $table = array(
    'header' => array(
      array(
        'data' => t('Title'),
      ),
      array(
        'data' => t('Operations'),
        'colspan' => 6,
      ),
    ),
    'rows' => array(),
  );

  foreach ($twig_templates_from_db as $key => $form_name) {
    $name = $form_name;
    $edit = l(t('Edit'), "admin/islandora/twigtemplates/{$key}/duplicate");
    $delete = l(t('Delete'), "admin/islandora/twigtemplates/{$key}/delete");
  
    $copy = l(t('Duplicate'), "admin/islandora/twigtemplates/{$key}/duplicate");
    $view = l(t('View'), "admin/islandora/twigtemplates/{$key}/view");
    $export = l(t('Download'), "admin/islandora/twigtemplates/{$key}/download");
    

    $table['rows'][] = array(
      $name,
      $copy,
      $edit,
      $view,
      $export,
      $delete,
    );
  }

  return theme('table', $table);
}