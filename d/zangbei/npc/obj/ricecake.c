 inherit ITEM;
inherit F_FOOD; 
void create()
{
        set_name("����", ({ "zanba" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���������������ɵĴ��š�\n");
                set("unit", "��");
                set("value", 15);
                set("fish_bait_zanba", 1);
                set("fish_bait", 1);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
        
}   
