//Cracked by Kafei
// by aln 2 / 98
// modified by aln 4 / 98

inherit F_CLEAN_UP;

#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
        object room, obj;
        string str;
        int lvl, cost, bonus;
        mapping learned;
int i;
        if( !(room = environment(me)) ) return 0;

        if( base_name(room) != "/d/xueshan/dadian" ) 
		{
			tell_object(me,"�㲻��ѩɽ�µĴ����ܽ�����");
        me->apply_condition("xsjob2", 3 + random(6));
me->delete_temp("xsjob2");
			return 0;
		}

        lvl = (int)me->query_skill("lamaism", 1);
        cost = 30000 / (30 + lvl);

		if( me->query("jing",1) < cost)
		{
			tell_object(me,"���о����ȣ��������㣬�޷�������");
			return 1;
		}

        me->receive_damage("jing", cost + random(cost));

        if( me->is_fighting() || me->is_busy() || !living(me) )
                return 1;

        if( duration < 1 ) {
                message_vision(HIR"\nһ��Сɮ������$N˵������ʦ�����ˣ�����Ϣһ�°ɡ�\n"NOR, me);
        me->apply_condition("xsjob2", 3 + random(6));
me->delete_temp("xsjob2");
                return 0;
        }

i=random(lvl);
if (i<40) i=40;
if (i>150) i=150;
if (!me->query_condition("xsjob2"))
{
        me->add( "potential", (i*1/2)+10 );
        me->add( "combat_exp", (i*2/3)+20 );
        me->improve_skill("lamaism", i/2);
        switch(random(13)) {
              case 0:
	        str = "һ������������춱���أ������ǻ۾����˴��������";
                break;
	      case 1:
		str = "֪����ջ�����������ת�����������ˣ���ʱ���ɵá�";
                break;
              case 2:
		str = "��������գ�ƽ�Ȳ�ת��������ʮ���磬���óɷ����";
                break;
              case 3:
		str = "�ڻ����޴����ɵ����޵á�����Բ���ʣ�����춴��У��ܷ������ġ�ĩ���������� �޴���а����";
                break;
              case 4:
		str = "�����굱֪��һ������������ʼ���������Դ���������Բ���Ľ�����";
                break;
              case 5:
		str = "������ջ������ն����ࡣ�ջ���������ձ��������ô������";
                break;
              case 6:
		str = "�����Բ�������Ĳ����ʡ���������������ĩ����������ӦԶ��á�";
                break;
              case 7:
		str = "���Ϥ���롣��ľ������ľ�����𡣾����޽��Σ����������ǡ�";
                break;
              case 8:
		str = "��ҵ�굱֪��һ��������������ִ�Ұ�����ʼ����ת��";
                break;
              case 9:
		str = "δ�������࣬���ó����ᡣ��������ģ����������";
                break;
              case 10:
		str = "�ǹʶ����ƣ���������ǡ����ܹ���ɲ����ȥ̰���գ�";
                break;
              case 11:
		str = "���������ģ����οɳɾ͡��������У�������������";
                break;
              case 12:
		str = "���������ѣ��ղ���а������������ģ������ǳɾ͡�";
                break;
	}

        message_vision(HIY"\n$N�û�ľ�����������" + str + "\n\n"NOR, me);
}
        me->start_busy(5 + random(cost/15));

        me->apply_condition("xsjob", duration - 1);
        return 1;
}

	
