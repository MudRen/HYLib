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
                "northwest":__DIR__"nanmen", 
                "east":__DIR__"sroad2", 
                "southwest":__DIR__"sroad6", 
	]));
       setup();
	replace_program(ROOM);
}
