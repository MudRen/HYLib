 // copyright c apstone, inc.
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("���Ѹ�", ({ "putaogan" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�������������Ǻ�˵����Ѹɡ�\n");
                set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 40);
                set("value", 30);
                set("food_remaining", 4);
                set("food_supply", 50);
        }
        setup();

}      
