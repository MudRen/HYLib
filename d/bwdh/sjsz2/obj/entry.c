//Cracked by Kafei
// Entry for Group BWDH
// Apache 10/98

inherit ITEM;

void create() {
    set_name("С��", ({ "entry"}) );
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "С���¼\n");
        set("no_get",1);
        set("no_clean_up", 1);
    }
    setup();
}
