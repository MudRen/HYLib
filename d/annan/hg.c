
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIY"���ϻʹ�"NOR);
  set ("long", @LONG
���ϻʹ������˱����ʹ���ͼֽ��������ᷢ���Լ�����
��һ����С��ı����ʹ��������Ͻ��ǣ��Ͻ������ַ�Ϊ����
�֣�ǰ���лʵ�ƽ�������������������лʵ۾�ס��Ǭ��
��ʺ�ס����̩������̫�Ӿ�ס�Ĺ��������������ס��
˳��Ժ�ȡ��ʳ��ڻ�������̨��̫�͵�ͼ��������ʵ۵Ĺ���
��������
LONG);

  set("exits", ([ 
"east":__DIR__"suishilu2",	

       ]));
  set("objects",([
	  __DIR__"npc/bing":4,
	  ]));

set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

