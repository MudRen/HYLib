
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
���˽�֪��̩ɽ�ۣ���ɽ�գ���ɽ�棬®ɽ�㣻Ȼ��������ɽ����
���ա��桢����һ�壬��Ȼ��ɡ�����ɽ�У��Ʋ���������Ŀ��Ȥ����
��ʯ�֡����桢���ġ����㣬�����ľ�����;�������澳����ʤ����
����Ů̶�������ҡ�С��ͤ�����˴�Լ�����ϵٽ�®������կ���������
����������ͨ���һ���죩�������ϱڣ�����֮�ţ������ٷ塢����
��������Ī�⣻������̶��ʮ��̶�������١����Ǿ��ģ���ɽè�����ڹ�
̨�����ʯ������ʯ������ʯ������ͷ�������������������ҡ���������
��Ⱥɽ��Գ�����ɽ�ȼ������Ȫ��
LONG);

  set("exits", ([ 

  "northeast":__DIR__"shalu1",
  "west":__DIR__"caodi1",
  
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

