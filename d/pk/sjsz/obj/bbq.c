//Cracked by Kafei
// BBQ 
// Copy from /u/kane/obj/toast

inherit ITEM;
inherit F_FOOD;

void create() {
    set_name("����", ({ "bbq" }) );
    set_weight(200);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "һ�鿾�ý�ƽ�ƵĿ��⣬����һ�ž�Ҫ����ˮ�ˡ�\n");
        set("unit", "��");
        set("value", 0);
        set("food_remaining", 2);
        set("food_supply", 50);
    }
    set("bwdhpk",1);setup();
}
