// Room: /ruzhou/xifu-tang.c //�ٰ��������
// llm 99/07/09

inherit ROOM;
void create()
{
	set("short", "ϲ����");
	set("long", @LONG
������ӭ��¥�Ķ�¥�����ؿ��԰�����ʮ���Ű����������й�
�Ŵ��ĺ�ɫϲ�֣����ڳ��������ڴ˾ٰ���磬����ĺ���Ҳ�ͳ�
�����������ź��Ĵ���̺��һ��ϲ������ľ�����վ��¥����
�����ɿ����̲���ˮ����ɽ���롣
LONG
);
	set("exits", ([
                "down" : __DIR__"yingbin-lou1",
	]));

	setup();
   replace_program(ROOM);
}
