// kufang1.c �ⷿ���Կ��ݣ�
// 11:55 99-1-16
#include <ansi.h>
inherit ROOM;
int do_yuntang(string arg);

void create ()
{
  set ("short", "�ⷿ");
  set ("long", @LONG
���߹�һ����խ��С��֮������һ��ֿ��С���������Ķ�����δ��
���̵Ĳ�ƥ��һЩ���¡���ǽ�ڷ��ż��Ŵ����ӣ������Ϸ��ż�ƥ��ʪ��
���Ϻ�һ������һ���Ѿ��յ÷��̵��ٶ�����������������(yuntang)��
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"fengreiroom",
]));

  setup();
}
void init()
{
        add_action("do_yuntang","yuntang");
}

int do_yuntang(string arg)
{
        object me=this_player(); 
        object ob;
        if (!me->query_temp("gongzuo/yunbu"))
           return notify_fail("������û���ٲ��Ĺ�����\n");

/*        if (query_temp("bu")==0)
           return notify_fail("����Ĳ��϶��Ѿ��ٺ��ˡ�\n");
*/
        if (!arg || arg != "����")
           return notify_fail("��Ҫ����ʲô��\n");

        if ( me->is_busy())
           return notify_fail("�������ٲ��ء�\n");

        if ( (int)me->query("jing")<20)
           return notify_fail("��̫���ˣ���Ϣһ�°ɡ�\n");

        if (me->query_temp("gongzuo/yunbu")==6)
           return notify_fail("�����Ѿ��ٺ��ˣ�����ٺõĲ�����ȥ�ɣ�\n");
   
  message_vision("$N�����ٶ��������ڲ����������ƶ���ֻ������������ð����ɫ��������\n",me);
      me->add("jing",-(10+random(10)));
      me->add_temp("gongzuo/yunbu",1);

  if ( (int)me->query_temp("gongzuo/yunbu")==6)
 {
  message_vision(CYN"��ƥ����������ƽ����$N����ƥ���ú����һ�ߡ�\n"NOR,me);
      ob=new("/d/city/obj/bu.c");
      ob->move(me);
      add_temp("bu",-1);      return 1;
 }
   me->start_busy(5);
  if (random(10)>7)
 {
  message_vision(RED"$N����������֮���𽥿�ʼ�������ģ�ֻ���á��ꡱ��һ��$N���ֱ��ٶ�����һ�¡�\n"NOR,me);     
       me->receive_damage("qi", (int)me->query("max_qi")/5);
 
 }             
  return 1;
} 
