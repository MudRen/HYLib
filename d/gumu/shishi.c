// shishi.c
#include <ansi.h>

inherit ROOM;

mapping *skills = ({
	(["name": "dafumo-quan", "max": 200]),
	(["name": "jiuyin-zhengong", "max": 100]),
	(["name": "jiuyin-shenfa", "max": 150]),
	});

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����Ҳ������֮������̧ͷ�����������Ҷ����������д�����ּ����ţ�
�㿴��һ�ᣬ���������ѽ⡣�Ҷ����Ͻǻ���һ��ͼ�������书�޹أ�����ϸ
���������Ƿ���ͼ��
LONG
        );

        set("exits", ([
                "up" : __DIR__"shiguan",
        ]));

	set("item_desc", ([
		"ͼ" : "���������Ƿ�ͼ�����в��ɴ�ϲ��ԭ���ǻ�����ǳ�Ĺ���ص���\n",
		"�Ҷ�" : "�㿴���Ҷ��������Ķ������������С�֡�\n",
	]) );

        setup();
//        replace_program(ROOM);
}

void init()
{
	add_action("do_look",  ({ "kan", "look" }));
	add_action("do_yandu",({"yandu"}));
}

int do_look (string arg)
{
	object me = this_player();
	
	if (me->query_temp("jiuyin/gumu") < 3)
		return 0;
	if( !arg || arg!="zi")
		return notify_fail("���뿴ʲô��\n");
	if (!me->query("jiuyin/gumu") && me->query("jiuyin/gumu-failed") > 2)
		return notify_fail("���Ѿ������ܶ�Σ��ٿ�Ҳûʲô�ĵ��ˣ�\n");
	message_vision(HIY"$N������ЩС�֣��ƺ�����һЩ�书Ҫ����\n", me);
	if (me->query("jiuyin/gumu")) {
		message_vision("$N��ȻһƳ�䣬��������С�֡������澭�ڹ�Ҫ���������˷ܼ��ˡ�\n", me);
		message_vision("$N�о���һ�£�����Ӧ�����ж�(yandu)Щ"HIB"���ħȭ��"HIY"(dafumo-quan)��\n", me);
		message_vision(HIB"�����湦"HIY"(jiuyin-zhengong)�Լ�"HIB"������"HIY"(jiuyin-shenfa)��Ƥë��\n"NOR, me);
		return 1;
	}
	if (me->query("kar") > 40 && random(20) == 0) {
		message_vision("$N��ȻһƳ�䣬��������С�֡������澭�ڹ�Ҫ���������˷ܼ��ˡ�\n", me);
		message_vision("$N�о���һ�£�����Ӧ�����ж�(yandu)Щ"HIB"���ħȭ��"HIY"(dafumo-quan)��\n", me);
		message_vision(HIB"�����湦"HIY"(jiuyin-zhengong)�Լ�"HIB"������"HIY"(jiuyin-shenfa)��Ƥë��\n"NOR, me);
		me->delete("jiuyin/gumu-failed");
		me->set("jiuyin/gumu", 1);
		message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+me->query("name")+"�ڹ�Ĺʯ���з����˾����澭�ڹ�Ҫ������\n"NOR, users());
		return 1;
	} else {
		message_vision("��������д�ļ����Ѷ���$N����һ��ͷ����ˡ�\n"NOR, me);
		me->add("jiuyin/gumu-failed", 1);
		return 1;
	}
}

int do_yandu(string arg)
{
	int cost, my_skill, max_level, i, flag = 0;
	string book, skill;
	object me = this_player();
	object where = environment(me);

	if (!me->query("jiuyin/gumu"))
		return 0;
	if (!arg)
		return notify_fail("��Ҫ��ʲô��\n");
	if (sscanf(arg, "%s %s", book, skill) != 2)
		return notify_fail("ָ���ʽ��yandu <����> <����>\n");
        if((int)me->query("learned_points") < 200 ) 
		return notify_fail("���Ǳ��̫���ˡ�\n");
	if (book != "yaojue")
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
	if( (int)me->query("potential") < 1 )
		return notify_fail("���Ǳ���Ѿ������ˣ�����ô��Ҳû�á�\n");
	if( (int)me->query("combat_exp") < 1000000 )
		return notify_fail("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
	if( me->query("int") < 25 || me->query_int() < 50 )
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
