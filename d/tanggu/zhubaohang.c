inherit ROOM;
void create()
{
        set("short", "�����鱦��");
        set("long", @LONG
����ү�˳��и��ˣ������Ľ����鱦�и�ʼ������ÿ���в��ٵĸ���
С�����˹�������鱦���Ρ��������������������ǲ������������ˡ�
LONG );
        set("exits", ([
                "west" : __DIR__"stnanjie2",
        	
	]));

	set("objects", ([
                __DIR__"npc/long" : 1,
      	]));

	setup();
}