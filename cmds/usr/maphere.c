//mapphere.c
//by llm*˭������ 1999/11/
/*˵�������ļ��������������ⷿ����һ�����õĲ���("outdoors","$*")����/doc/������
mapĿ¼���������������Ŀ¼ͬ���ĵ�ͼ�ı��ļ���Ȼ���������ļ����ٽ������ͼͬ
�������ָ�����ɫ����һ����ʵ�ֵ��൱�򵥣�Ҳ�в��㡣����Ҫ�����򷿼��ļ�д���൱
�淶������һ����������ò�Ҫ���ظ����Ƶĵ�����������ļ�Ҳ�����ÿ��Դٽ����ֹ淶�ɣ�*/

#include "ansi.h"
#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me)
{
	int i;
	string file,map,name, *search;

	seteuid(getuid());
    
	if( !file = environment(me)->query("outdoors"))
		return notify_fail("�����ƺ����ܲ鿴��ͼ���뵽���⡣\n");
	name = environment(me)->query("short");
    if( file_size("/doc/map/" + file)>0 ) 
    {
		if(stringp(map = read_file("/doc/map/" + file)))
		{
		    map = replace_string(map, name, HIR+name+NOR);
		    me->start_more(map);
		    return 1;
		}
	}
	return notify_fail("��ʱ��û�п�������ĵ�ͼ��ѯ��\n");
}

int help(object me)
{
	write(@HELP
ָ���ʽ��map 
���ָ���ṩ���������ѯ���ڵصĵ�ͼ������ɫ��ʾ������֮�ء�
�����������ڲ��������У�
HELP
	);
	return 1;
}

