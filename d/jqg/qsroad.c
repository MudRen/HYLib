//qsroad.c ��ʯ��·
inherit ROOM;
void create()
{
          set("short","��ʯ��·");
	  set("long",@LONG
�����߹�������·������˵����ǰ������ʯ�嵹�Ǻ�����˼����ʪ�ֻ���
��ÿ��ʯ��ļ�϶֮�У���������ɫ����̦��һֻ�׺�ʩʩȻ�ض���������ʯ
���ϣ���ʱ�������������Լ���ë������ɷ�ǿɰ���������Լ������һ����
ʯ�ݡ�
LONG
);
          set("outdoors","�����"); 
	  set("exits",([
              "eastup": __DIR__"shuitang",
              "north": __DIR__"shiwu",
          ]));
          setup();
	  replace_program(ROOM);
}
