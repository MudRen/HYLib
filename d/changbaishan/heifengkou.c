
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ڷ��");
  set ("long", @LONG
���������������ɽ�ĺڷ�ڡ����ﳤ�����Ҷ��Ǵ�硣������
���Х����ɰ��ʯ�����Ǹ���վ��������ֻ��������������ڡ����ڷ�
���ֿ��Ա��������ٲ���ȫò��
LONG);

  set("exits", ([ 
 "northeast":__DIR__"wenquan",
 "northdown":__DIR__"shanlu6",
         ]));
  set("outdoors","cbs");
  	set("objects", ([

"quest/skills2/wunon/dalie/dalie" : 2,

	]));
  set("valid_startroom", 1);
  setup();
 
}

