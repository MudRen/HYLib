// liangong-fu.c

inherit ITEM;
#include <ansi.h>
//int do_shouzhang();
int consider_lv(object ob,int a);
static int i = random(11)+5;
void create()
{
        set_name("��ɮ������", ({ "ling pai"}));
        set("long", "һ�������³��õ���ɮ������,����������ͱ����ɮzuanyan�书");
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "paper");
                set("value", 0);
                set("unit", "��");
        }
        setup();
}

void init()
{
        add_action("do_shouzhang","zuanyan");
}
int do_shouzhang(string arg)
{
object ob,me=this_player();
string targ;
if (!arg||!ob=present(arg,environment(me)))
               return notify_fail("��Ҫ��˭������ѧ��\n");
if(!me->query_temp("wsdjob"))
return notify_fail("�㲻�����������������\n");
targ=ob->query("name");
if (userp(ob))
return notify_fail("�����ʲô!!�ǲ���Ŀ��\n");
if ( targ != me->query_temp("wsdjob") )
return notify_fail("���ǽ����"+me->query_temp("wsdjob")+"������ѧ������!!\n");
if (this_object()->query("usename")!=me->query("name"))
return notify_fail("�ⲻ�������ɮ������!!\n");

        if (me->is_busy())
        {
          tell_object(me,"����æ���أ�\n");
          return 1;
        }
	if( me->is_fighting() )
        {
          tell_object(me,"�ȴ����ˣ���˵�ɣ���\n");
          return 1;
        }

        if ((me->query("jing") < 50))
        {  
          tell_object(me,"��ľ������ܼ��У�\n");
          return 1;
        }
        if ((me->query("qi") < 50 ))
        {
          tell_object(me,"�������״̬̫��!\n");
          return 1;
        }

message_vision(HIW"\n$N��$nһ��һ�Ե������������湦--"+me->query_temp("wsdskl") + "!\n"NOR,me,ob);
                        me->add("jing",-10);
                        me->add("qi", -5);
                        me->start_busy(1);
me->add_temp("wsjob",1);
if (me->query_temp("wsjob") >i)
{
message_vision(HIW"\n$n��$N˵����,�������������ɣ���Ҳ���ˡ�\n"NOR,me,ob);
message_vision(HIG"$N������ɣ������ƽ�����$n��\n"NOR,me,ob); 
me->start_busy(5);
call_out("destroying", 0, me);                       
}
        return 1;
}
void destroying(object me)
{   
int exp,pot;
if (!me) return;
exp=80+random(80);
pot=60+random(60);
	   tell_object(me,HIW"�㱻�����ˣ�\n" + 
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                       NOR);
me->apply_condition("slwsd_busy",2);
        me->delete_temp("wsdjob");
        me->delete_temp("wsdskl");
        me->delete_temp("wsjob");
        me->add("combat_exp",exp);
        me->add("potential",pot);
        destruct(this_object());
}