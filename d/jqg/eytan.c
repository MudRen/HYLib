// eytan.c ����̶
// By River 99.5.25
inherit ROOM;
#include <ansi.h>
void create()
{
          set("short",HIB"����̶"NOR);
          set("long",@LONG
���������ģ���ֻ����������ˮ�в�������Ǳ�����������Ի�����ˮ��
���������ˮ�����˼�������ͻȻ�����ŵ�һ���ȳ���ͬʱ����ˮ����������
������޴�ˮ����Ϯ��
LONG
);

          set("objects",([
             __DIR__"npc/eyu": 1,
             __DIR__"npc/eyu1":1,
          ]));

          set("indoor","�����");
          setup();
}

void init()
{
        add_action("do_ta","ta");
}

int do_ta(string arg)
{
     object me = this_player();
     if(! arg || arg !="corpse") return 0;
     if(!objectp(present("corpse", environment(me)))) return 0;
     if( arg =="corpse"){
      if (me->is_busy() || me->is_fighting())
            return notify_fail("����æ���ģ�\n");
      message_vision(HIC"$N����̤���������ϣ��辢Ծ�𣬽�������������ı���һ�㡣$N��Ծ���԰���\n"NOR,this_player());
      me->move(__DIR__"cave1");
      tell_room(environment(me), me->name() + "�Ӷ԰���Ծ������\n", ({ me }));
      return 1;
      }
      return notify_fail("��׼��̤��ʲô������ӣ�\n");
}
