// Room: /d/hainan/xialuo 
#include <ansi.h>
inherit ROOM; 
 
void create() 
{ 
  set ("short", "������");
  set ("long", @LONG
�ı߰���һƬ,��Х������紵�����۾�����������.��ǰ�ľ���
�ɿ���ӹ�,��ֻ�ܸо����Լ��ڿ��ٵ��½���.
LONG);

  setup();
}
int init()
{
    object me;
    me=this_player();
    call_out("greeting",1,me);
}
void greeting(object me)
{ 
       tell_object(me,RED+"ֻ����'ͨ'��һ������,����亣��!\n"+NOR);
me->unconcious();
     if (me->query("gender")=="����")
	 me->move(__DIR__"xuanya.c");
     else 
      me->die();

}
