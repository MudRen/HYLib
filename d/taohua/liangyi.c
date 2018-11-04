// Room: /u/jpei/thd/liangyi.c

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "����");
	set("long", @LONG
���������ǲ㣬��һ�����������ϵ����ݾͱ������ˡ�������һ��������
�����ݣ�ͨ������㡣��ν���ǣ�ϵָ������������Ķ��ˡ���Ȼ̫����Բ��
���ɶ�������ͳһ�Ķ������ɡ�����֮�䲻ͣת����������Ϣ�����������е�
ԭ������Ȼ������֮����Ȼ���Ǿ��ԵĶ�������ν�������������к������ǹ�
������̫����������̫�����������������԰˸���ά���ۣ��޾��ڶ�����Ϊ
���ţ�ν֮�������������϶�Ϊ���ţ�ν֮����
LONG
	);
	set("exits", ([ 
		"northeast" : __DIR__"yin",
		"southwest" : __DIR__"yang",
		"down" : __DIR__"sixiang",
	]) );

	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_save", "save");
	add_action("do_quit", "quit");
}

int do_save()
{
	write("���ﲻ׼���̣�\n");
	return 1;
}

int do_quit()
{
	write("���ﲻ׼�˳���\n");
	return 1;
}

