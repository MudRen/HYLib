
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�Ž����");
  set ("long", @LONG
������һ�Ҳ�ݡ����ھŽ����������˺ܶ࣬���Բ�ݵ�����ܺá�
�м�������������һ�ߺȲ裬һ�������ŵ���Ĵ��¡��Ա߻��м�������
�Ĺٱ����Ա�����������ϰ�ʶ���ԶԶ�ض㵽��һ�ߡ�
LONG);

  set("exits", ([ 

  "east":__DIR__"beidajie1",
        ]));
   set("objects",([
	   __DIR__"npc/cha":1,
	   __DIR__"npc/chake":2,
	   __DIR__"npc/mitan":1,
	   ]));
   set("resource/water",1); 
  set("valid_startroom", 1);
  setup();
 
}
void init()
{
   object ob;
   ob=previous_object();
   if((userp(ob)&&!query("fight_flag")&&
      random(10)+random(10)>=14)){
   	set("fight_flag",1);
   	call_out("auto_fight",0);}
}

void auto_fight()
{
  object ob1,ob2;
  object *ob;
  int i;
  ob=all_inventory(this_object());
  for(i=0;i<sizeof(ob);i++){
    if(ob[i]->query("kill_npc"))
      ob1=ob[i];
    if(ob[i]->query("target"))
      ob2=ob[i];}
  if(!ob1||!ob2) return;

  if(environment(ob1)!=environment(ob2)||
     environment(ob1)!=this_object()||
     environment(ob2)!=this_object())
  return;
  message_vision(HIW"$N��$n��Ц������̸�۵�����δ������ˣ���\n"NOR,ob1,ob2);
  ob1->kill_ob(ob2);
  return;
}
