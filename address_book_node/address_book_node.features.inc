<?php
/**
 * @file
 * address_book_node.features.inc
 */

/**
 * Implements hook_views_api().
 */
function address_book_node_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function address_book_node_node_info() {
  $items = array(
    'contact' => array(
      'name' => t('Contact'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
