// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��Ƥ��");
        set("long", @LONG
��ֻ�������ڰ�գ��������ˣ�����ţͷ�������Լ�Ϊ�������ַ�
���˷�ͷ�����ڣ�Ȼ�����ˮ������������һ����������Ƥ��������
Ż���ظ�֮���̣�һ����˹��һţͷ���ƺ������������˼����Ȼ˵
����ʮ����֮ͽ���Ǵ˲��ܽ����İ����ظ�֮�У���ᵫ���й�������
������ˣ��㻹�����Ͳ�ס���������ĥ������ȥ��
LONG
        );
        set("exits", ([
		"up" : __DIR__"bashe",
		"down" : __DIR__"moai",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-160);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
