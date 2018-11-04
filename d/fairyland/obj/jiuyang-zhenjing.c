// jiuyang-zhenjing.c
// Modified by jpei
#include <ansi.h>
inherit ITEM;
mapping *skills = ({
	(["name": "lieyan-dao", "max": 400]),
	(["name": "liehuo-jian", "max": 400]),
	});
void create()
{
	set_name(HIR"�����澭"NOR, ({"jiuyang zhenjing", "jiuyang", "zhenjing", "book"}));
	set_weight(600);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ı������ľ��顣�������dujing jiuyang zhenjing��������
�����һ�����������������һ�ֵ�����lieyan-dao)����һ�ֽ���(liehuo-jian)�����ͨ������fanyue��������\n");
		set("value", 800000);
		set("material", "paper");
		set("no_drop", "��ô���������ؼ�����ɲ������ⶪ����\n");
		set("no_get", "�������������˵ı�������˯����Ҫ����ͷ�棬���޷���ȡ��\n");
                set("treasure", 1);
	}
}

void init()
{
	add_action("do_yandu",({"fanyue"}));
        add_action("do_du", "dujing");
        add_action("do_du", "studyjing");
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        mapping skill;
        int jylevel, neili_lost;

        if (!id(arg)) return 0;

        if (where->query("pigging")){
                write("�㻹��ר�Ĺ���ɣ�\n");
                return 1;
        }
        if (me->is_busy()) {
                write("��������æ���ء�\n");
                return 1;
        }

        if( me->is_fighting() ) {
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
        }

        if (!me->query_skill("literate", 1)) {
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }
        
        if (me->query("jing") < 60) {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }
	if (me->query_skill("force",1) < 20) {
		write("����ڹ�����û�д�ã��������������񹦡�\n");
		return 1;
	}
	if (me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
 	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("guiyuan-tunafa",1) )
	return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����񹦣���\n");


        jylevel = me->query_skill("jiuyang-shengong", 1);
	if (jylevel < 30)
		neili_lost = jylevel / 2;
	else if (jylevel < 70)
		neili_lost = jylevel * 2 / 3;
	else if (jylevel < 120)
		neili_lost = jylevel * 3 / 4;
	else
		neili_lost = jylevel;
	if (jylevel >= (me->query_skill("force", 1) + 30)) {
		write("��������ڹ��Ļ����������ٻ�ø���һ�����ߡ�\n");
		return 1;
	}
	if (jylevel / 5 >= me->query_int()) {
		write("����������Բ������޷���һ����ϰ��һ��ľ����񹦡�\n");
		return 1;
	}
	if (me->query("neili") < neili_lost) {
		write("�������������޷�������ô������书��\n");
                return 1;
        }
        if (me->query("combat_exp") < jylevel * jylevel * jylevel / 10) {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        }
	if (jylevel >= 200) {
                write("���Ѿ��޷��ٴӾ���������ʲô��Ҫ�и��ߵ���Ϊ�����������ˡ�\n");
                return 1;
        }
	if (jylevel >= 120 && me->query("neili") < me->query("max_neili") + jylevel) {
                write("�����һ�����ϵ����ݹ�����£��⿿�ж����������������޷��ٻ�ý����ġ�\n");
                return 1;
        }
        me->receive_damage("jing", 50);
        me->add("neili", -neili_lost);
	if (!jylevel) {
		write("�㷭����һ�ᾭ�飬�������澡���������������ģ���ÿһ��֮��ȴ��ӬͷС��д�����й����֡�\n");
		write("�㶨һ���񣬴�ͷϸ�������������������ǹ������������ľ��ϡ�\n");
	        write("�㿪ʼ�ж���һ�ᣬ���潲�����Ǿ��������Ż�����\n");
	}
	if (jylevel >= 120)
	        write("�㰴��������������һ���ٶ������ж��������澭�����һ�ᣬ����е��ĵá�\n");
	else
	        write("���ж��������澭���������ĵá�\n");
	me->improve_skill("jiuyang-shengong", me->query_skill("literate", 1) / 3 + 1);
	if (!random(5)) message("vision", me->name() + "����һ�������������С�\n", environment(me), ({me}));
	if (me->query_skill("jiuyang-shengong", 1) > jylevel) {
		if (jylevel == 29) {
		        write("������˵�һ�ᣬ������������������Ż���������ѧ��\n");
		        write("�㿪ʼ�ж��ڶ��ᣬ���潲�������������š�\n");
		}
		else if (jylevel == 69) {
		        write("������˵ڶ��ᣬ��Ȼ���������������������Щ�Ѷȣ����ǲ�û��̫��µĵط���\n");
		        write("�㿪ʼ�ж������ᣬ���潲������������Ҫ��\n");
		}
		else if (jylevel == 119) {
		        write("������˵����ᣬ�����������������Ҫ��Ϊ�������˺ô�ľ�����ȫ����ˡ�\n");
		        write("�㿪ʼ�ж����Ĳᣬ���潲�����Ѿ���ʮ�ּ�����ڹ���Ҫ���������൱���ѡ�\n");
		}
		else if (jylevel == 199) {
		        write("�����ڶ����˵��Ĳᣬ�ҹ����һҳ֮���������ǻ�ϲ����΢΢�е���㯡�\n");
		        write("��ָ����������Ĺ����ҴҶ���������ʼ����Բ����\n");
if (!me->query("jiuyangok/con"))
{
			me->add("con", 1);
me->set("jiuyangok/con",1);
}
		}
	}
	return 1;
}
int query_autoload()
{
       return 1;
}
int do_yandu(string arg)
{
	int cost, my_skill, max_level, i, flag = 0;
	string book, skill;
	object me = this_player();
	object where = environment(me);

	if (!arg)
		return notify_fail("��Ҫ��ʲô��\n");
	if (sscanf(arg, "%s %s", book, skill) != 2)
		return notify_fail("ָ���ʽ��yandu <����> <����>\n");
	if (book != "jiuyang")
		return notify_fail("��Ҫ��ʲô�飬���Ǿ����澭(jiuyang)��\n");
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
		return notify_fail("Ҳ����ȱ��ʵս���飬�����������˵�Ķ��������޷���ᡣ\n");
	else
		write("���ж����й�" + to_chinese(skill) + "�ļ��ɣ��ƺ���Щ�ĵá�\n");
	me->improve_skill(skill, ((int)me->query_skill("literate", 1) / 5 + 1));
	me->receive_damage("jing", cost);
	me->add("potential", - random(2));
	return 1;
}
