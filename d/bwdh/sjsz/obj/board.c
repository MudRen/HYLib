//Cracked by Kafei
// Board for Group BWDH
// Apache 10/98

inherit ITEM;

void create() {
    set_name("�������ɼ���", ({ "board"}) );
    set_weight(10000);
    set_max_encumbrance(500000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "�������ɼ�����ű��������ǵ�ȫ���ɼ���");
        set("value", 10000);
        set("material", "steel");
        set("no_get",1);
        set("no_clean_up", 1);
    }
    setup();
}
