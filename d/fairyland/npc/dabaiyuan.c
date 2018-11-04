// dabaiyuan.c
// By jpei

inherit NPC;

int do_cut(string arg);

void create()
{
        set_name("���Գ", ({ "da baiyuan", "da", "baiyuan", "yuan" }) );
        set("race", "Ұ��");
        set("age", 54);
        set("long", "һֻ�����Ű�ë����Գ������ŧѪģ��������һ���󴯡�\n��ϸ���ŷ��֣��������ϵ�ͻ���Ǳ��������߷���ʲô��ȥ��������Ҫ����֮�����С�\n");

        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 1000);
    
	set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 10);

        setup();
	if (clonep()) call_out("disappear", 120);
}

void init()
{
	add_action("do_cut", ({"cut", "sever", "ge", "heal", "zhi", "yizhi", "zhiliao"}));
	::init();
}

void disappear()
{
	message_vision("$N������ã�Ҳû���˾������������ȥ�ˡ�\n", this_object());
	destruct(this_object());
}

int do_cut(string arg)
{
	object thread, yaocao;
	object me = this_player();

	if (id(arg)) {
		if (!present("sharp rock", me))
			return notify_fail("��ϧ����ͷû�е�����\n");
		if (!present("fish bone", me) || !thread = present("xi si", me))
			return notify_fail("��ϧ����ͷû�����ߡ�\n");
		if (!yaocao = present("yao cao", me))
			return notify_fail("��ϧ����ͷû�в�ҩ��\n");
		destruct(thread);
		destruct(yaocao);
		remove_call_out("disappear");
if (!me->query("jiuyangget"))
{
		new("/d/fairyland/obj/jiuyang-zhenjing")->move(me);
		new("/d/fairyland/obj/pantao")->move(me);
		write("���ü�ʯ�������Գ�Ǹ��Ϸ첹��֮����ֻ�����澹����һ���Ͳ���������һ������һ�׾��顣\n");
		write("��ʱ����������ϸ��飬æ���뻳�С�Ȼ����������룬��Ƥ��ɵ�ϸ˿���ߣ���ǿ�����˰�Գ���˿ڡ�\n");
		write("��Ѳ�ҩ�����˸��������˴�����Գʮ�ָм��㣬������һ�������Ĵ���ң�Ȼ�����ˡ�\n");
                me->set("jiuyangget",1);
                me->set("jiuyangok",1);
 }
      		destruct(this_object());
	}
	return 0;
}
