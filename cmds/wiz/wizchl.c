// wizchl.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if (!arg) return notify_fail("����Ҫ˵ʲô��\n");
        shout(HIC+"������֪ͨ��"HIY+HBBLU+ me->name() +"(" + me->query("id") +")"+"��" +HIY+HBBLU+ arg + "\n" + NOR);
//if (me->query("id")!="hxsd")
//{
//     write(HIC+"������֪ͨ��"HIY+HBBLU+ me->name() +"(" + me->query("id") +")"+"��" +HIY+HBBLU+ arg + "\n" + NOR);
//}
        write(HIC+"������֪ͨ��"HIY+HBBLU+ me->name() +"(" + me->query("id") +")"+"��" +HIY+HBBLU+ arg + "\n" + NOR);
	return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : wizchl <ѶϢ>
 
���ָ������ʦר�õ�.�����Ǹ�����ʾ���ǳ�
cool��sj��wizҲ�������hoho��wizard����
�ȼ�����ʦ����ʹ�á�
 

HELP
    );
    return 1;
}
 
