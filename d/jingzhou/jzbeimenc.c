// Room: /d/jingzhou/jzbeimen
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short", "���ݱ���" );
        set("long", @LONG
�����Ǿ��ݵı��ţ����ھ����������Ǿ���Ҫ�أ���˳�ǽ��ʵ�ޱȣ���
¥�߸����������ڱ������⣬����ϡ�٣��������˲��࣬���Թٱ��ķ���Ҳ��
��ʮ�����ܡ�
LONG
        );
	set("objects", ([
		__DIR__"npc/bing" : 2,
]));
 
        set("exits", ([
  
	"northup" :"/d/wudang/wdroad2",
	"south" :__DIR__"beidajie2",
  
]));

        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        setup();
        replace_program(ROOM);
}

