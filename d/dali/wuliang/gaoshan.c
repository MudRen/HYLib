// cool 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
����������ɽ�ĸ߷��ϣ��ž����ˡ�ֻ��ɽ���º�¡����¡���������ȵ�
ˮ�����ϴ����������¿����������׽��ƺƵ����Ĵ�ɽ����ӿ����ɷ��׳�ۡ�
����ɽ���ǽ��ߣ���������ʱ���ɭ�֡�
LONG
	);
        set("outdoors", "����");
	set("exits",([
             "south" : __DIR__"shanlu12",
             "westdown" : __DIR__"anbian",	
	]));

        set("objects", ([
	      __DIR__"obj/yeguo" : 2,
	]));
	setup();
	replace_program(ROOM);
}
