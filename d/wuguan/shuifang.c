inherit ROOM;

void create()
{
    set("short", "ˮ��");
    set("long", @LONG
һ���ݣ��㿴�����ڷ��ż��ڴ�ף�������װˮ�õģ��������ƺ�����
�յģ�����û��һ���ˣ��������˶����ˡ�
LONG);
	set("exits", ([
	     "east" : __DIR__"houyuan",
        ]) );
        set("no_fight",1);
        set("outdoors", "���");
	setup();
        replace_program(ROOM);
}

