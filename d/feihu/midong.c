//��������
//by steel
#include "ansi.h"
//#include <mimi.h>
inherit ROOM;
void create()
{
     set("short",HIR"��������"NOR);
     set("long",@LONG
     ���߽���һ���ܶ�,�����쳣�ĸ���,���ܹ��߻谵,�����м�������,
��Χɢ����һЩ����,��Ȼ��Щ����ǰ�����������ϱߵ�ʯ��(bi)���ƺ�
���ż���С�֡����ı����Ϻ����и�ת��(pan)�Ƶġ�
LONG
       );                 
     set("item_desc",([
        "bi":HIB"���������������ݺ�����ʮ���أ���ɱ����֮�������󹶾ӵ�\n"
"λ��Ȼ�������˲��磬�������˷��Ừ�ģ��ĺκ��գ���ǲ�ܳ��ر��ڴ�\n"
"�Ա���ɽ����֮�ã�Ȼ��֪������ն������Į�����������ң���֮�κ�!\n"
"�˼��������ȡ����ԭ֮����������ν֮���塣����С�ӽ��ô˶����ɾ�\n"
"ȡ֮���Լ����¡�����˽��֮�ģ�������ǲ��\n"NOR,
   ]) ); 
    set_temp("breaken",0); 
    set("objects",([
          __DIR__"npc/corpse":5,
    ]) ); 
  setup();        
}

void init()
{
   add_action("do_break","break");
   add_action("do_turn","turn");
}

int do_break(string str)
{
   object ob;//room,gold
   ob=this_player();  
   if(!str||str!="bi") return 0; 
   if(this_object()->query_temp("breaken")) return notify_fail("ʯ������!\n");
   if((int)ob->query("neili")<5000)
   {
     message_vision(HIR"���ֻ��һ���ƺߣ�$N��ʯ�ڵķ����������ǰһ��....\n"NOR, this_player());
                this_player()->set("neili",0);
                this_player()->unconcious();
        return 0; 
   }
   this_object()->set_temp("breaken",1);
   message_vision(HIW"$Nֻ��һ�����죬ʯ�ڱ�ͱ���ˣ�ԭ��������һ����\n"NOR, this_player());
if((int)this_player()->query("����")<1){
this_player()->add("combat_exp",5000);
this_player()->set("����",1);
}
    this_object()->set("exits/south", __DIR__"midong2");
   
    this_player()->add("neili",-1000);

  return 1;
}
int do_turn(string arg)
{
    object ob;
    ob=this_player();
    if(!arg) return 0;
    if(arg=="pan"){
    this_object()->set("exits/up",__DIR__"bingya");
    message_vision(YEL"$N�����������죬ͷ����¶������!\n"NOR,ob);
    call_out("close",5);
    return 1;
    }
}
int close()
{
   this_object()->delete("exits/up");
   write(YEL"�������������죬���ֺ�����!\n"NOR);
   return 1;
}
