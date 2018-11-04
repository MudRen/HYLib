// study.c
#include <ansi.h>
#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object where = environment(me);
	object ob;
	string zhao_name, book_name;
	mapping skill;
	int my_skill, cost, times, i, success=0;

	if(!arg)
		return notify_fail("��Ҫ��ʲô��\n");
        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if (where->query("sleep_room"))
                return notify_fail("���Ҳ��ܶ��飬��Ӱ�������Ϣ��\n");

       if( environment(me)->query("no_beg") &&
       environment(me)->query("no_fight") &&
       environment(me)->query("no_steal")) 
          return notify_fail(HIY"\n��ҪӰ����ˣ�������һ����ĵط��ɡ�\n"NOR);

	if( me->is_fighting() )
		return notify_fail("���޷���ս����ר�������ж���֪��\n");
	if(sscanf(arg, "%s %d", book_name, times)!=2 )
		return notify_fail("ָ���ʽ��study|du <����> <����>\n");
	if (times < 1 || times > 30)
		return notify_fail("�����������һ�Σ����Ҳ���ܳ�����ʮ�Ρ�\n");
        if (!me) return notify_fail("û�Ȿ��ɶ�����\n");
        if (!present(book_name, me)) return notify_fail("û�Ȿ��ɶ�����\n");

	if(!objectp(ob = present(book_name, me)) )
		return notify_fail("û�Ȿ��ɶ�����\n");

	if( !mapp(skill = ob->query("skill")) )
		return notify_fail("���޷�����������ѧ���κζ�����\n");

	if( !me->query_skill("literate", 1) )
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

	message("vision", me->name() + "��ר�ĵ��ж�" + ob->name()
		+ "��\n", environment(me), me);
	if( (int)me->query("combat_exp") < skill["exp_required"] )
	{
                me->start_busy(1);
		write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
		return 1;
	}

	notify_fail("����Ŀǰ����������û�а취ѧ������ܡ�\n");
	if( !SKILL_D(skill["name"])->valid_learn(me) ) return 0;

	cost = skill["jing_cost"] + skill["jing_cost"] 
		* (skill["difficulty"] - (int)me->query("int"))/20;
	if (cost < 10) cost = 10; // minimum cost

	if( me->query_skill(skill["name"], 1) > skill["max_skill"] )
	{
                me->start_busy(1);
		return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
//			write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
		return 1;
	}
	if( me->query_skill(skill["name"], 1) < skill["min_skill"] )
	{
                me->start_busy(1);
		return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫����ˣ������ջ�\n");
//			write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫����ˣ������ջ�\n");
		return 1;
	}

	if( !me->query_skill(skill["name"], 1) ) me->set_skill(skill["name"], 0);

	if( (int)me->query("jing") < cost * times )
{
                me->start_busy(1);
	        return notify_fail("��ľ��������ˡ�\n");
}
	my_skill = me->query_skill(skill["name"], 1);
if( (string)SKILL_D(skill["name"])->type()=="martial"
&&	my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") )
		return notify_fail("Ҳ����ȱ��ʵս���飬��û����ѧϰ��������ˡ�\n");

	if( (int)me->query("jing") > cost * times )
	{
		if( (string)SKILL_D(skill["name"])->type()=="martial"
		&&	my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") )
		{
                me->start_busy(1);
			printf("Ҳ����ȱ��ʵս���飬���%s������˵�Ķ��������޷���ᡣ\n", ob->name());
		}
		else
		{
			if(zhao_name = SKILL_D(skill["name"])->query_skill_name(my_skill))
			printf("���ж���"+chinese_number(times)+"���й�%s�ļ��ɣ��ԡ�%s����һ���ƺ���Щ�ĵá�\n", 
				to_chinese(skill["name"]), zhao_name);
			else
			printf("���ж���"+chinese_number(times)+"���й�%s�ļ��ɣ��ƺ��е��ĵá�\n", to_chinese(skill["name"]));
			for (i = 1; i <= times; i++)
			{
				me->improve_skill(skill["name"], (int)me->query_skill("literate", 1)/5+1);
			}
		}
	} else {
                me->start_busy(1);
		cost = me->query("jing");
		return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
//		write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
	}

	me->receive_damage("jing", cost * times );

	return 1;
}

int help(object me)
{
   write( @HELP
ָ���ʽ: study|du <��Ʒ����> <����>

���ָ��ʹ�����ͨ���Ķ����Ż�������Ʒ��ѧĳЩ����,
��ǰ����: �㲻���Ǹ�����ä����

see also : learn
HELP
   );
   return 1;
}
