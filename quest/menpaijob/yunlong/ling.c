// liangong-fu.c

inherit ITEM;
#include <ansi.h>
//int do_shouzhang();
int consider_lv(object ob,int a);
static int i = random(13)+10;
void create()
{
        set_name("��������", ({ "xuanchuan ziliao"}));
        set("long", "һЩ��������,����������������һ�㸺������(xuanchuan)����");
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "paper");
                set("value", 0);
                set("unit", "Щ");
        }
        setup();
}

void init()
{
        add_action("do_shouzhang","xuanchuan");
}
int do_shouzhang()
{
object ob,me=this_player();
string targ;
object obj;
int maxpot,b;

if (!environment(me))  return notify_fail("���ﲻ��Ҫ���������ĵط�!\n");
if (me->query_temp("yljob2/changxi") < 1)
return notify_fail("û�����ڽ������������!\n");
if (!environment(me)->query("outdoors"))
return notify_fail("�뵽�����˶�ĵط�������!\n");
if (environment(me)->query("outdoors") !=me->query_temp("yljob2/where"))
return notify_fail("���ǽ��㵽"+me->query_temp("yljob2/cx")+"ȥ��������!\n");
if (me->query_temp("yljob2/done") >= 1)
{
        tell_object(me,"�������������ˣ���ȥ�칦�ɡ�\n");
         return 1;
}


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

message_vision(HIY"\n$N��"+me->query_temp("yljob2/cx") + "����������!\n"NOR,me);
b=random(4);
if (b==0)
message_vision(CYN"\n$N˵���ҵȶ��Ǻ��ˣ�����������ͳұ������!\n"NOR,me);
else if (b==1)
message_vision(RED"\n$N˵���������������ǣ���֪���˶��ٰ���!\n"NOR,me);
else if (b==2)
message_vision(WHT"\n$N˵������Ϊ����ѹ���ˣ�����������֪�����˶�����ʶ֮ʿ!\n"NOR,me);
else message_vision(GRN"\n$N˵���ҵ���ػᣬ�鲼���֮�䣬���ܷ��帴��!\n"NOR,me);
me->add("jing",-10);
me->add("qi", -5);
me->start_busy(1);
me->add_temp("yljob",1);
if( !environment(me)->query("no_fight"))
{
if (random(50)==1 && me->query("combat_exp") > 1000000)
{
obj=new(__DIR__"menggu"); 
obj->move(environment(me));
obj->do_copy(me,maxpot,2);
obj->set("title",HIM"��͢צ��"NOR);
obj->set("usename",me->query("name"));
me->start_busy(1);
message_vision(HIR"����ͻȻ������һ�ˣ�\n"NOR, obj);
message_vision(HIR"$N˵������ػᷴ�������������\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
}

if ((int)me->query_temp("yljob") >i && 
!me->is_fighting())
{
message_vision(HIM"$N�����������������ĺܺ�,���������˾���ʾ֧�ַ��帴����\n"NOR,me);
message_vision(HIC"$N������ɣ������е��������Ϸ��������ˡ�\n"NOR,me,ob); 
me->set_temp("yljob2/done",1);
me->set_temp("yljob",0);
me->delete_temp("yljob");
me->start_busy(3);
call_out("destroying", 0, me);                       
}

        return 1;
}
void destroying(object me)
{   
if (!me) return;
        me->delete_temp("yljob");
        destruct(this_object());
}