#include"lvgl/lvgl.h"

static lv_obj_t* create_slider(lv_color_t color);


lv_obj_t* red_slider, * green_slider, * blue_slider;

lv_obj_t* base_obj;



void slider_callback(lv_event_t* e)
{
    lv_color_t color = lv_color_make(lv_slider_get_value(red_slider), lv_slider_get_value(green_slider), lv_slider_get_value(blue_slider));
    lv_obj_set_style_bg_color(base_obj, color, LV_PART_MAIN);
}



void rgb_mixer_ui(void)
{
   //create slider
    red_slider = create_slider(lv_palette_main(LV_PALETTE_RED));
    green_slider = create_slider(lv_palette_main(LV_PALETTE_GREEN));
    blue_slider = create_slider(lv_palette_main(LV_PALETTE_BLUE));

    lv_obj_align(red_slider, LV_ALIGN_LEFT_MID, 30, 0);
    lv_obj_align_to(green_slider, red_slider, LV_ALIGN_OUT_RIGHT_MID, 30, 0);
    lv_obj_align_to(blue_slider, green_slider, LV_ALIGN_OUT_RIGHT_MID, 30, 0);

    //base object
    base_obj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(base_obj, 85, 175);
    lv_obj_align_to(base_obj, blue_slider, LV_ALIGN_OUT_RIGHT_BOTTOM, 25, 0);
    lv_obj_set_style_border_color(base_obj, lv_color_black(), LV_PART_MAIN);
    lv_obj_set_style_border_width(base_obj, 5, LV_PART_MAIN);

    //label
    lv_obj_t* heading = lv_label_create(lv_scr_act());
    lv_obj_align_to(heading, blue_slider, LV_ALIGN_TOP_MID, -10, -40);
    lv_label_set_text(heading, "RGB MIXER");

    lv_obj_add_event_cb(red_slider, slider_callback, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(green_slider, slider_callback, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(blue_slider, slider_callback, LV_EVENT_VALUE_CHANGED, NULL);
}




static lv_obj_t* create_slider(lv_color_t color)
{
    lv_obj_t* slider = lv_slider_create(lv_scr_act());
    lv_slider_set_range(slider, 0, 255);
    lv_obj_set_size(slider, 10, 175);
    lv_obj_set_style_bg_color(slider, color, LV_PART_KNOB);
    lv_obj_set_style_bg_color(slider, lv_color_darken(color, LV_OPA_40), LV_PART_INDICATOR);
    return slider;
}

