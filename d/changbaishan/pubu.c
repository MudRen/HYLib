
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����ٲ�");
  set ("long", @LONG
����ɽ���¶���ˮ���ļ���һ����ȥ����һ��б�������ݡ��ٲ���
��һ��ʯ�����ٲ���Ϊ���ɡ��ٲ�״���������������������������
��������ȵף��侰��εΪ׳�ۡ�������ˮ���ٲ����γ���Լ��ʮ�ɵ�
ˮ̶��
LONG);

  set("exits", ([ 
 "northup":__DIR__"baiyun-feng",
 "southdown":__DIR__"shanlu2",
 "eastup":__DIR__"shanlu6",
 "westup":__DIR__"longmen-feng",
        ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

