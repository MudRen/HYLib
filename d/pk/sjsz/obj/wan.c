//Cracked by Kafei
// Wan
// Apache 09/28/98

inherit ITEM;

void create() {
    set_name("����",({ "wan"}) );
    set_weight(50);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "������һ�����վƣ�������һ��ˬ�ĺܡ�\n");
        set("unit", "��");
        set("value", 0);
    }
    set("bwdhpk",1);setup();
}

void init() {
    add_action("do_drink", "drink");
}

int do_drink(string arg) {
    object me = this_player();

    if( !this_object()->id(arg) ) return 0;

    if( (int)me->query("water") >= (int)me->max_water_capacity() )
        return notify_fail("���Ѿ���̫���ˡ�\n");

    me->add("water", 50);

    write("��һ��ͷ����һ���վƺȵĸɾ���ȴ�о�ûʲôζ����\n");
    write("���૵�������������̵ģ�����ʲô�����˶���ˮ����\n");
       
    destruct(this_object());

    return 1;
}
