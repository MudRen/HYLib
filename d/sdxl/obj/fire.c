// Obj: /u/poq/sdxl/obj/fire.c ����
// bye poq@jyqx 97/7

inherit ITEM;

int decayed;

void init();

void create()
{
    set_name("����",({"fire", "huozhe"}));
    set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
        set("long", "���ۣ��������������͵��\n");
        set("unit", "��");
        set("value", 50);
	 }
    setup();
}

void init()
{
    add_action("do_use", "use");
    add_action("do_use", "yong");
}

int do_use(string arg)
{
    object me = this_player();
    object ob = this_object();
    object where = environment(me);

    if (arg != "fire" && arg!="huozhe")
        return notify_fail("��Ҫʹ��ʲô��\n");

    if(ob->query_temp("temp/used")==1)
        return notify_fail("�����Ѿ�����ȼ�ˣ�\n");

    message_vision("$N��ȼ�˻��ۣ���Χ��������������\n", me);

    decayed = 0;

    set_name("��ȼ�Ļ���", ({ "fire", "huozhe" }) );
    set("long", "������ȼ�š�\n");
    where->add_temp("temp/light", 100);
    ob->set_temp("temp/used", 1);
//    if( clonep(this_object()) )
    call_out("decay", 120, 2);

    return 1;
}

void decay(int phase)
{
    object me = this_player();
// object ob = this_object();
    object where = environment(me);
	decayed = phase;
	switch(phase) {
		case 1:
            say( "����ȼ��������\n" );
            set_name("��ȼ�Ļ���", ({ "fire", "huozhe" }) );
            set("long", "������ȼ�š�\n");
            where->add_temp("temp/huo", 100);
			call_out("decay", 120, phase + 1);
			break;
		case 2:
            say( "��������Ҫ���ˡ�\n" );
            set_name("��Ϩ��Ļ���", ({ "fire", "huozhe" }) );
            set("long", "��������ҪϨ���ˡ�\n");
            where->add_temp("temp/huo",  -50);
	call_out("decay", 60, phase + 1);
			break;
                case 3:
            say( "����Ϩ���ˡ�\n" );
            where->add_temp("temp/huo",  -50);
			destruct(this_object());
			break;
	}
}
