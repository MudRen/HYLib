#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;

mapping *skills = ({
	(["name": "jiuyin-zhengong", "max": 1000]),
	(["name": "daode-jing", "max": 200]),
	(["name": "jiuyin-shenzhua", "max": 200]),
	(["name": "jiuyin-shenzhang", "max": 200]),
	(["name": "jiuyin-shenfa", "max": 200]),
	(["name": "dafumo-quan", "max": 200]),
	(["name": "xuanyin-jian", "max": 200]),
	(["name": "yinlong-bian", "max": 200]),
	});

void create()
{
	string desc = "";
	int i;

        set_name(HIB"�������澭��"NOR, ({ "jiuyin zhenjing", "zhenjing" }));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		for (i=0; i<sizeof(skills); i++)
			desc += sprintf("\t%s (%s)\n", to_chinese(skills[i]["name"]), skills[i]["name"]);
                set("long",HIC"����һ���������������������ѧ�ؼ�������д�ţ��������澭����������ж����µļ��ܣ�\n\n"HIW+desc+"\n"NOR);
                set("treasure", 1);
                set("value", 0);
                set("material", "skin");
                set("no_drop", 1);
                set("no_put", 1);
                set("no_give", 1);
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
	int cost, my_skill, max_level, i, flag = 0;
	string book, skill;
	object me = this_player();
	object where = environment(me);

	if (!me->query("jiuyin/full"))
		return 0;
	if (!arg)
		return notify_fail("��Ҫ��ʲô��\n");
	if (sscanf(arg, "%s %s", book, skill) != 2)
		return notify_fail("ָ���ʽ��yandu <����> <����>\n");
	if (book != "zhenjing")
		return 0;
	for (i=0; i<sizeof(skills); i++)
		if (skill == skills[i]["name"]) {
			max_level = skills[i]["max"];
			flag = 1;
			break;
		}
	if (!flag)
		return notify_fail("���޷���" + this_object()->name() + "��ѧ��������ܡ�\n");
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
	if((int)me->query("potential") - (int)me->query("learned_points") < 200 ) 
         return notify_fail("���Ǳ��̫����!\n");	

	if( (int)me->query("learned_points") < 1 )
		return notify_fail("���Ǳ���Ѿ������ˣ�����ô��Ҳû�á�\n");

	if( (int)me->query("potential") < 1 )
		return notify_fail("���Ǳ���Ѿ������ˣ�����ô��Ҳû�á�\n");
	if( (int)me->query("combat_exp") < 1000000 )
		return notify_fail("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
	if( me->query("int") < 30 || me->query_int() < 60 )
		return notify_fail("����Ŀǰ��������������û�а취ѧ������ܡ�\n");
	notify_fail("����Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");
	if( !SKILL_D(skill)->valid_learn(me) )
		return 0;
	cost = 40 * (1 + (50 - (int)me->query("int")) / 20);
	if (cost < 10) cost = 10; // minimum cost
	if((int)me->query("jing") < cost) {
                me->start_busy(1);
	        return notify_fail("��ľ��������ˡ�\n");
	}
	my_skill = me->query_skill(skill, 1);
	if (my_skill > max_level)
		return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
	if (my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp"))
		return notify_fail("Ҳ����ȱ��ʵս���飬��Բ���������˵�Ķ��������޷���ᡣ\n");
	else
		write("���ж����й�" + to_chinese(skill) + "�ļ��ɣ��ƺ���Щ�ĵá�\n");
	me->improve_skill(skill, ((int)me->query_skill("literate", 1) / 5 + 1));
	me->receive_damage("jing", cost);
	me->add("potential", - random(2));
	return 1;
}

int query_autoload() { return 1; }
