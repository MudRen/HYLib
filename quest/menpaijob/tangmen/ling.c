// liangong-fu.c

inherit ITEM;
#include <ansi.h>
//int do_shouzhang();
int consider_lv(object ob,int a);
static int i = random(9)+3;
void create()
{
        set_name("��������", ({ "tm lingpai"}));
        set("long", "һ����������,�������ĵ���һ�㸺�𻤳�����huchen");
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
        add_action("do_shouzhang","huchen");
}
int do_shouzhang()
{
object ob,me=this_player();
string targ;
object obj;
int maxpot;
if (!environment(me))  return notify_fail("���ﲻ��Ҫ�㻤�ǵĵط�!\n");
if (environment(me)->query("short") !=me->query_temp("tmhwjob"))
return notify_fail("���ǽ��㵽"+me->query_temp("tmhwjob")+"ȥ������!\n");
if(!me->query_temp("tmhw"))
return notify_fail("�㲻�����������������\n");
if (this_object()->query("usename")!=me->query("name"))
return notify_fail("�ⲻ�������������!!\n");

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

message_vision(HIY"\n$N��"+me->query_temp("tmhwjob") + "վֱ�����������Ƽұ�!\n"NOR,me);
me->add("jing",-10);
me->add("qi", -5);
me->start_busy(1);
me->add_temp("tmjob",1);
if( !environment(me)->query("no_fight"))
{
if (random(10)>7)
{
obj=new(__DIR__"shaolin"); 
obj->do_copy(me,maxpot,2);
obj->set("title",HIW"�����ɰ���"NOR);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N��Ц����������Ҫ��ʶ��ʶ����������ʲô����?\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
else if (random(10)>7)
{
obj=new(__DIR__"emei"); 
obj->do_copy(me,maxpot,2);
obj->set("title",HIG"�����ɰ���"NOR);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N��Ц����������Ҫ��ʶ��ʶ����������ʲô����?\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
else if (random(10)>7)
{
obj=new(__DIR__"wudang"); 
obj->do_copy(me,maxpot,2);
obj->set("title",HIY"�䵱�ɰ���"NOR);     
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N��Ц����������Ҫ��ʶ��ʶ����������ʲô����?\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
}
if (me->query_temp("tmjob") >i && 
!me->is_fighting())
{
message_vision(HIY"$N����ʱ���Ѿ����ˣ������������ˡ�\n"NOR,me);
message_vision(HIG"$N������ɣ������ƽ����˱�ĵ��ӡ�\n"NOR,me,ob); 
me->start_busy(5);
call_out("destroying", 0, me);                       
}

        return 1;
}
void destroying(object me)
{   
int exp,pot;
if (!me) return;
exp=120+random(81);
pot=90+random(51);
	   tell_object(me,HIW"�㱻�����ˣ�\n" + 
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                       NOR);
        me->delete_temp("tmjob");
        me->delete_temp("tmhw");
        me->delete_temp("tmhwjob");
 	me->add("combat_exp",exp);
	me->add("potential",pot);
        destruct(this_object());
}