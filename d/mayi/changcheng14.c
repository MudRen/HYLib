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
            	"northwest" : __DIR__"changcheng13",
            	"eastdown" : __DIR__"changcheng15",
            	"southwest" : __DIR__"shanlu1",
	]));
       setup();
	replace_program(ROOM);
}
