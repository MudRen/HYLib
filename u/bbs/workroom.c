inherit ROOM;
#include <ansi.h>

void create()
{
set("short", "ɱ�ֵĹ�����");
set("long", @LONG
������ɱ�ֵĹ����ҡ������� bbs ͵���ĵط�
LONG	);	
set("valid_startroom",1);
set("no_steal", "1");
set("exits", ([ /* sizeof() == 1 */   "down" : "/d/wizard/wizard_room", ])); 
          setup();
}
