// /d/gaoli/fenghuotai
// Room in ɽ����
// rich 99/04/05
inherit ROOM;
void create()
{
	set("short", "���̨");
	set("long", @LONG
�����ǳ��ǵķ��̨���Ŵ��Է���ţ�ÿ���ео����ַ���ʱ��
�͵�ȼ�����򸽽��ľ��ӱ��ţ�������̨��Ϊս���Ծ��ķ��ˡ�
LONG
	);
set("outdoors", "mayi");
set("valid_startroom", 1);
set("exits", ([
            	"northeast" : __DIR__"changcheng18",
            	"southup" : __DIR__"changcheng16",
	]));
       setup();
	replace_program(ROOM);
}
