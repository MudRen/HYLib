
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ˮ����ͤ");
  set ("long", @LONG
ˮ����ͤˮ����ͤλ���Ϻ����ģ�ʼ�����ƴ�����������
�䣬��Ϊ��������֮��¦���ġ���ױ̨����������䣬һ��
Ϊ�����λ�������ơ��ӻ�¥�����������ڴ�������ӽ���峯
ʱΪ����¦����ļ���޽���ʼ���������֡���Ǭ¡��ʮ���꣨
1788�꣩����ʱ�ĳơ�����ͤ�����ֳơ�ˮ����ͤ����
LONG);

  set("exits", ([ 
  "north":__DIR__"hupan",
  "southwest":__DIR__"nanan2",
  "northeast":__DIR__"yhs",
        ]));
   set("objects",([
       __DIR__"npc/daoke":1,
       ]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

