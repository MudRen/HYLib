// Room: /d/jingzhou/jzximen
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short", "��������" );
        set("long", @LONG
���������ݵ����ţ������������Ǿ���Ҫ�أ���˳�ǽ��ʵ�ޱȣ���
¥�߸��������������ţ���̤���˼��յ������һֱ���츩֮����ȥ��·
�϶������裬�����Ҫȥ�Ļ�����ض��С�ġ����˳��ţ����뾣�ݣ���
�͵��ڵ�����ԭ�ˡ�
LONG
        );
	set("objects", ([
		__DIR__"npc/bing" : 2,
 ]));

        set("exits", ([
  
 "east": __DIR__"xidajie2",
 "west": __DIR__"shudao1",
]));

        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        setup();
        replace_program(ROOM);
}

