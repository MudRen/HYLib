// /d/taiyuan/nroad1.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "��ٵ�");
	set("long", @LONG
����һ������ʯ�̳ɵ��������Ϊ����̫ƽ�Ĺ�ϵ�����������˿�
�̻��Ƚ϶࣬�����߾�Ҫ������ϵĵؽ��ˣ���������Կ���̫ԭ�ĳ�
ǽ��
LONG
        );
set("outdoors", "taiyuan");
set("valid_startroom", 1);
set("exits", ([
                "north":__DIR__"sroad6", 
                "south":__DIR__"sroad8", 
	]));
       setup();
	replace_program(ROOM);
}
