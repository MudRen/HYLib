// liangong-fu.c

inherit ITEM;
#include <ansi.h>
//int do_shouzhang();
int consider_lv(object ob,int a);
static int i = random(13)+8;
void create()
{
        set_name("������", ({ "wuxing qi"}));
        set("long", "һ��������,�������ĵ���һ�㸺��Э��(xiezhu)����");
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
        add_action("do_shouzhang","xiezhu");
}
int do_shouzhang(string arg)
{
object ob,me=this_player(),obj;
string targ;
int maxpot;
if (!arg||!ob=present(arg,environment(me)))
               return notify_fail("��ҪЭ��˭��\n");
if(!me->query_temp("mj2job"))
return notify_fail("�㲻����������������\n");
targ=ob->query("name");
if (userp(ob))
return notify_fail("�����ʲô!!�ǲ���Ŀ��\n");
if ( targ != me->query_temp("mj2job") )
return notify_fail("���ǽ���Э��"+me->query_temp("mj2job")+"��������!!\n");
if (this_object()->query("usename")!=me->query("name"))
return notify_fail("�ⲻ���������!!\n");

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

message_vision(HIC"\n$N��$nΪ�˷���Ԫ������ʼŬ������!\n"NOR,me,ob);
message_vision(HIG"\n$N�߸ɻ�ߺ��ź����ĺ��ӣ�������Ԫ��������ʥ�̡�����\n"NOR,me,ob);
                        me->add("jing",-10);
                        me->add("qi", -5);
                        me->start_busy(1);
me->add_temp("mjjob2",1);
if( !environment(me)->query("no_fight"))
{
if (random(60)==1 && me->query("combat_exp") > 1000000)
{
obj=new(__DIR__"menggu"); 
obj->move(environment(me));
obj->do_copy(me,maxpot,2);
obj->set("title",HIC"Ԫ��̽��"NOR);
obj->set("usename",me->query("name"));
me->start_busy(1);
message_vision(HIR"����ͻȻ������һ�ˣ�\n"NOR, obj);
message_vision(HIR"$N˵�������˽���������˵ȴ�������ܽ���\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
}
if (me->query_temp("mjjob2") >i)
{
message_vision(HIW"\n$n��$N˵����,����Ļ����������ˣ���Ϣȥ�ɡ�\n"NOR,me,ob);
message_vision(HIG"$N������ɣ������콻����$n��\n"NOR,me,ob); 
        me->set_temp("mjjob2",0);
        me->delete_temp("mjjob2");
me->start_busy(5);
call_out("destroying", 0, me);                       
}
        return 1;
}
void destroying(object me)
{   
int exp,pot;
if (!me) return;
exp=60+random(80);
pot=45+random(50);
	   tell_object(me,HIW"�㱻�����ˣ�\n" + 
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                       NOR);
me->apply_condition("mj2_busy",2);
        me->delete_temp("mj2job");
        me->delete_temp("mjjob2");
        me->add("combat_exp",exp);
        me->add("potential",pot);
        destruct(this_object());
}