// /u/beyond/ningbo/majiu.c ���
// Beyond make 1996.6.8
inherit ROOM;
void create()
{
set("short", "���");
set("long",@long
���Ǳ���ֱ��ϵ���ǣ����깩Ӧ���ʲ��ϡ���˵�˵���紾�ӣ�����
Ҫס�꣬����Ǿͻ����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�
Ǭ������һֱ�ź򵽿��������·������жѷ������Ѳ��ϣ�������һ����
�ۡ�
long);
        set("outdoors", "ningbo");
	set("exits", ([
		"northeast" : __DIR__"ningbocheng",
		"east" : __DIR__"kedian",

	]));

/*	set("objects", ([
		__DIR__"npc/mafu" : 1,
                __DIR__"obj/ma" : 3,
	]));
*/
	setup();
}

