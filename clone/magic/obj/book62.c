// �¹�������

#include <ansi.h>
inherit ITEM;
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

void create()
{
        set_name(HIC"�¹�������"NOR, ({ "moon axes", "62axes" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ħ���������ʹ��(spell id)�����ħ����\n") ;

                set("unit", "��");
                set("value", 50000);
                set("zhen", 3);
        }
        setup();
}

void init()
{
        add_action("do_shot","spell");
}

int do_shot(string arg)
{
        object me,ob,target;
        int myskill , tgskill;
        int mylev ,damage;

        me = this_player();

 	if (!id(arg))
	return notify_fail("��Ҫʹ��ʲô���᣿\n");
        if( !arg ) return notify_fail("�����˭ʹ�����Լ����᣿\n");

        target = me;


        if( me->query("combat_exp")< 500000)
        return notify_fail("��ľ���̫���ò��ˣ�\n");


        if(me->is_busy() )
                return notify_fail("����æ���ġ�\n");

        if( this_object()->query("zhen") < 1 ) {
        message_vision(HIC"\n$N"HIC"�ϵ�ħ������������!  $N"HIC"��ʧ�ˡ�\n"NOR,this_object(),target);
        destruct(this_object());
return 1;
                }

        if( !objectp(ob = present("moon axes", me)) )
                return notify_fail("��û�����ֶ�����\n");

        message_vision(HIC"\n$N"HIC"�����ϣ�������ʥ֮�¹⣬$n���ϵ������˲���!\n"NOR,this_object(),target);

	if((int)target->query("qi") < (int)target->query("max_qi")+(int)target->query("max_qi")/3)
        {
        target->add("qi",target->query("eff_qi")/3);
        target->add("eff_qi",target->query("eff_qi")/3);
if (target->query("qi") > target->query("max_qi")+1000)
target->set("qi",target->query("max_qi")+1000);
if (target->query("eff_qi") > target->query("max_qi"))
target->set("eff_qi",target->query("max_qi"));
        }
	if((int)target->query("jing") < (int)target->query("max_jing")+(int)target->query("max_jing")/3)
        {
        target->add("jing",target->query("eff_jing")/3);
        target->add("eff_jing",target->query("eff_jing")/3);
if (target->query("jing") > target->query("max_jing")+1000)
target->set("jing",target->query("max_jing")+1000);
if (target->query("eff_jing") > target->query("max_jing"))
target->set("eff_jing",target->query("max_jing"));

         }

        this_object()->add("zhen", -1);
        me->start_busy(1) ;
        return 1;
}
