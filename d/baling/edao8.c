// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "����Ͽ");
	set("long", @LONG
������Ϫ��,�����Ͻ��,��ʷ�����亽������,��ʯ����,̲��ˮ
�������۾��ն������������Դ��������Ķ�������ˮ��������ƽ��
��Ȼ���������ɡ���Ҫ���ۣ������С����鱦��Ͽ������ţ�����Ͽ
�����ϰ��С���ӰϿ���ȡ���ӰϿ���ڴ����ϰ�����ɽ�ϣ����Ŀ����
�����μǡ�����ɮʦͽ���ڵ���ʯ��
LONG
	);

	set("exits", ([
		"northwest" : __DIR__"edao5",
                "southwest" : __DIR__"edao9",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


