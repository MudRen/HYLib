// sz,obj:yinzhen.c                
// 97.10.1  by Aug

#include <weapon.h>
inherit THROWING;

void create()
#include <ansi.h>

{
	set_name(HIW"����"NOR, ({ "yinzhen" , "yin zhen", "zhen"  }) );
	set_weight(200);

	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "ö");
		set("long",
HIW"����һö���糤�����룬ϸ�����ͣ���Ϊҽ�Ҵ�Ѩ����֮�á�
���������������ҽ�߶�Ϊ������ҽ�����������ڹ���
����������������������(zhenjiu)(heal)��\n"NOR);
		set("value", 100);		
		set("yingdu", 50);
		set("base_unit", "ö");
		set("base_weight", 10);
		set("base_value", 1000);
		set("no_drop",1);
		set("no_give",1);
		set("no_sell",1);
		set("no_get",1);
		set("material","crimsonsteel");
		set("wield_msg", HIW"$N��Ƥ�����ó�һ��$n"+HIW"�������\n"NOR);
		set("unwield_msg", HIW"$N�����е�$n"+HIW"�Ż�Ƥ�ҡ�\n"NOR);
	}
	set_amount(1);
	init_throwing(30);
	setup();
}

void init()
{
	add_action("do_heal","zhenjiu");
 	add_action("do_heal","heal"); 
}

int do_heal(string arg)
{
	object me,ob;
	int damage,heals,i,exp,pot,score;
	string msg,s;

	me=this_player();
	if( living(me) ==0 ) return 0;

	if( ! this_object()->query("equipped"))
		return notify_fail("�����붼û�ó�������ôʩ���������?\n");

      if( me->query_skill("miaoshouhuichun", 1)<1 )
		return notify_fail("�������ֻش���������Ĺ���ûѧ�ᣬ����ʹ���������?\n");

	if( !arg || !objectp(ob = present(arg, environment(me)) ))
		return notify_fail("�����˭ʩ���������\n");
	
//��һ����Ϊ�˷�ֹ ���ֻش� ��Ϊ���� perform
	if(!userp(ob))
	{
                if( me->query_skill("miaoshouhuichun", 1)<30 )
		{
			message_vision(
"$N���$n���ˣ���$n���˿�$N�������֣�����¶�����µ���ɫ��
$n������$N������Ѩ���ˡ�\n",me,ob);
			return 1;
		}
	}
	else
	{
		if( ob!=me && ob->query("env/agree_heal")!=1 )		
		{
			message_vision(YEL"$N���$nʩ��������ˡ�\n"NOR,me,ob);
			tell_object(me,YEL"��Ϊ"+ob->name()+"����ҿ��Ƶ������ȴ��Է��Ĵ𸴡�\n"NOR);
			tell_object(ob,
YEL"�����ͬ��Ļ��������û�������agree_healΪ1(set agree_heal 1)��
�粻ͬ��Ͳ�Ҫ��������������������������ó����ⲻΪһ������\n"NOR);
			
			return 1;
		}
	}			

	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() || ob->is_fighting() )
		return notify_fail("ս���л������ˣ�����������\n");

// 5% ���²��ƣ���ֹpl ����ֹ����robot ����
        if( (ob->query("max_qi")*10/ob->query("eff_qi")) > 200 )
                return notify_fail(ob->name()+"�ܵ���̫���ˣ����ھ�ʩ�����̫Σ���ˣ�\n"); 

        if(ob->query("max_qi") == ob->query("eff_qi"))
	{
		if(me!=ob)
			return notify_fail("��Ҫ�ε�����ˣ���û���˰���\n");
		else
			message_vision("$N�������Լ��������飬������Լ����ֻش���ˮƽ��\n",me);
	}

        if( me->query("neili") < 50 )
		return notify_fail("����������㣬�޷�ʹ�����ֻش�����\n");
        if( me->query("jing") < 30 )
		return notify_fail("��ľ����㣬�޷����о�����\n");

        me->add("neili",-50);
        me->add("jing",-30);               
	me->improve_skill("miaoshouhuichun", random(me->query_int())/2);
	tell_object(me,"��ʵ����������ֻش�ˮƽ�����ˡ�\n");
             exp =1+random(20);
             pot = exp/7;
             score = random(2)+1;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
     	      tell_object(me,"�㱻�����ˣ�\n" +
             chinese_number(exp) + "��ʵս����\n"+
             chinese_number(pot) + "��Ǳ��\n" +
            chinese_number(score)+"���ۺ�����\n");

	if(me==ob) s="$N"; else s="$n";

	msg= CYN"$N�������룬С���������"+s+"��Ѩ����ȥ��\n"NOR;

	if( random(60)>(int)me->query_skill("miaoshouhuichun",1))
	{
                damage=random(ob->query("max_qi")/2);
		
                i=ob->query("max_qi")*10/damage;

		if(i>100)
			msg+= CYN"����$N������ƫ��û�����ô���Ѩ����"+s+"����¶��һ˿�ѹ������顣"NOR;
		else
		{
			if(i>40)
				msg+= HIR"����$N�������ͣ���Ȼ�̳���Ѫ�����������еĴ�ɣ�"NOR;
			else
				msg+= RED"$N������ȥ�ŷ��̴ִ���Ѩ����"+s+"���ۡ��������һ����Ѫ������������Σ�գ�����"NOR;
		}

                ob->receive_wound("qi",damage);                         
		
		damage=i;
	}
	else
	{
		msg+= CYN"$N������׼ȷ����Ĵ���Ѩ������������Ļ���ת����"+s+"�����ĳ���һ��������ɫ�ÿ����ˡ�"NOR;

		damage=-1;

		heals= me->query_skill("miaoshouhuichun", 1)+ random(me->query_skill("miaoshouhuichun", 1)) ;
                if((ob->query("eff_qi")+heals) > ob->query("max_qi"))
                        ob->set("eff_qi",ob->query("max_qi"));
//                        ob->set("qi",ob->query("max_qi"));
		else
                        ob->add("eff_qi",heals);
//                        ob->add("qi",heals);
        }

	msg+= "\n";
	
	if(me==ob)
		message_vision(msg,me);
	else
		message_vision(msg,me,ob);

	if(damage>0)
	{
                if(ob->query("qi")<0)
		{
                        ob->set("eff_qi",1);
                        ob->set("qi",1);

			if( userp(ob) )
			{
				if(me==ob)					
					message_vision("���հ���$N��һ����Լ�������\n",me);
				else
					message_vision("���հ���$N��һ���$n������\n", me,ob);
			}
		}
		else
		{
			if (me!=ob)
			{
				if(random(damage)<40)
				{
					message_vision("$N���������һ����ŭ��������ɱ�Ұ���\n",ob);

					ob->kill_ob(me);
					me->fight_ob(ob);
				}
				else
				{
					message_vision("$N���������һ������ʹ�����´����ǧ���ĵ㣡\n",ob);
				}
			}
		}
		
	}

	return 1;
}


