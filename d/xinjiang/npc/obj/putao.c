 // copyright c apstone, inc.
inherit ITEM;
inherit F_FOOD; 
void create()
{
        set_name("�޺˰�����", ({ "grape" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���ոմ����Ѽ�����ժ�������޺˰����ѡ�\n");
                set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 40);
                set("value", 30);
                set("value", 50);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
        setup();

}      
