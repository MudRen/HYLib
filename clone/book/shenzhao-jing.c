#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;

void create()
{
        set_name(HIW"���վ�"NOR, ({ "shenzhao jing", "jing" }));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",HIG"����һ��ʧ���Ѿõ���ѧ�ؼ�����������������ڹ���������ǿ�������ķ��š�\n"NOR);
                set("treasure", 1);
                set("value", 0);
                set("material", "skin");
                set("no_put", 1);
                set("no_give", 1);
                set("no_drop", 1);
                set("no_get", 1);
                set("no_steal", 1);
        }
}

void init()
{
	add_action("do_yandu",({"yandu"}));
}

int do_yandu(string arg)
{
	int cost, my_skill;
	string book;
	object me = this_player();
	object where = environment(me);

	if (!me->query("szj/passed"))
		return 0;
	if (!arg)
		return notify_fail("��Ҫ��ʲô��\n");
	if (sscanf(arg, "%s", book) != 1)
		return notify_fail("��Ҫ��ʲô��\n");
	if (!(book == "shenzhao jing" || book == "jing"))
		return notify_fail("��Ҫ��ʲô��\n");

	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");
	if (where->query("sleep_room"))
		return notify_fail("���Ҳ��ܶ��飬��Ӱ�������Ϣ��\n");
	if( me->is_fighting() )
		return notify_fail("���޷���ս����ר�������ж���֪��\n");
	if( !me->query_skill("literate", 1) )
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
	if (!random(5))
		message("vision", me->name() + "��ר�ĵ��ж�" + this_object()->name() + "��\n", environment(me), me);

	if( (int)me->query("learned_points") < 1 )
		return notify_fail("���Ǳ���Ѿ������ˣ�����ô��Ҳû�á�\n");
	if((int)me->query("potential") - (int)me->query("learned_points") < 200 ) 
         return notify_fail("���Ǳ��̫����!\n");	

	if( (int)me->query("potential") < 1 )
		return notify_fail("���Ǳ���Ѿ������ˣ�����ô��Ҳû�á�\n");
	if( (int)me->query("combat_exp") < 1000000 )
		return notify_fail("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
	if( me->query("int") < 30 || me->query_int() < 60 )
		return notify_fail("����Ŀǰ��������������û�а취ѧ������ܡ�\n");
	notify_fail("����Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");
	if( !SKILL_D("shenzhao-jing")->valid_learn(me) )
		return 0;
	cost = 100 * (3 + random(3));
	if (me->query("szj/over200"))
		cost = cost / 5;
	if((int)me->query("jing") < cost) {
                me->start_busy(1);
	        return notify_fail("��ľ��������ˡ�\n");
	}
	my_skill = me->query_skill("shenzhao-jing", 1);
	if (!me->query("szj/over200") && my_skill > 200)
		return notify_fail("�㰴�����վ��ķ���ͼ��ͨ�ζ�������ȴʼ��û���κν�չ��\n");
	if (my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp"))
		return notify_fail("Ҳ����ȱ��ʵս���飬��Բ���������˵�Ķ��������޷���ᡣ\n");
	else
		write("���ж����й����վ��ļ��ɣ��ƺ���Щ�ĵá�\n");
	me->improve_skill("shenzhao-jing", ((int)me->query_skill("literate", 1) / 5 + 1));
	me->receive_damage("jing", cost);
	me->add("potential", - (1 + random(2)));
	return 1;
}

int query_autoload() { return 1; }
