// Room: /d/city/yizhan.c

inherit ROOM;

void create()
{
	set("short", "��վ");
	set("long", @LONG
���Ǹ�����վ��սʱ�����ͺ�ǰ������������ġ���Ϊ��ʱ����
���Ÿ�����ʹ�ã�����ûʲô�ɲι۵ġ����������������ƽʱ��Ϣ��
�ط�����ǰ�������Ϸ��˼�����⣬���м�����ˮ��
LONG
	);

	set("exits", ([
		"south" : __DIR__"qinglong-2",
	]));
        
        set("objects",([
         __DIR__"obj/dagao":4,
  "/clone/npc/man":2,
         ]));
    set("no_fight",1);
        set("resource/water",1);
	setup();
	replace_program(ROOM);
}

