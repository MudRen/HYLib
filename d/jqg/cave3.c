// cave3.c ��
inherit ROOM;
#include <room.h>
void create()
{
          set("short","��");
          set("long",@LONG
��������һ���������ѿ�ֱ�����ߣ��������ã�ʼ�ղ�����ͷ����
��ȴԽ��Խƽ��ͻȻ���������״���һ���Ц֮�����⼸��������Ц��������
ȴ����ſ�һ�㣬����쳣���������С�
LONG
);

          set("exits",([
             "west": __DIR__"shiyao",
          ]));
           
          setup();
          replace_program(ROOM);
}
