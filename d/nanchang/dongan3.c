
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����������ڶ���������ʼ�����ϳ��������䣨502��519�꣩��ԭ
Ϊԥ����ε��֮ʦ���㵥���׵�סլ�����������£�����լ��һ��ʱ����
������һ�����֮����̫�����547�꣩�ĳƴ���¡� �ƿ�Ԫ��䣬��
�ƿ�Ԫ�¡�����4�꣨769�꣩�����ڸ�ɮ�����һ������˵�����ķ���ͽ
�Ƽ����ޣ����ҵ���139�ˣ�ʹ��Ԫ�³�Ϊ���Ϸ�ѧ���ġ�
LONG);

  set("exits", ([ 
 "northeast":__DIR__"dongan1",
 "southwest":__DIR__"nanan1",
        ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

