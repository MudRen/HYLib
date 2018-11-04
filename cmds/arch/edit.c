// edit.c
#include "/doc/help.h"
inherit F_DBASE;
inherit F_CLEAN_UP;
void create()
{
        seteuid(getuid());
        set("name", "�༭ָ��");
        set("id", "edit");            
        set("channel_id","���߱༭");
}
int main(object me, string file)
{
        if( !file ) return notify_fail("ָ���ʽ��edit <����>\n");
        if( in_edit(me) ) return notify_fail("���Ѿ���ʹ�ñ༭���ˡ�\n");
        if (!(int)SECURITY_D->valid_write(resolve_path(me->query("cwd"), file),me,"write"))
                return notify_fail("��û���㹻�Ķ�дȨ����\n");
                  log_file("edit/"+geteuid(me), sprintf("edit %s %s\n", resolve_path(me->query("cwd"), file), ctime(time())) );
        seteuid(geteuid(me));

if( !sscanf(file, "/u/%*s") ) 
return notify_fail("����/u/Ŀ¼�´��������ļ�!!\n");

        ed(resolve_path(me->query("cwd"), file));

        if(!me->query("env/no_edit_msg"))
        CHANNEL_D->do_channel(this_object(),"sys",me->query("name")+"("+me->query("id")+")"+"��д��"+resolve_path(me->query("cwd"),file)+"��");
        return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : edit <����>, edit here
���ô�һָ���ֱ�������ϱ༭������
                /��ǰ����ƥ����
                ?�������ƥ����
                =��ʾ��ǰ��������
                a�ڵ�ǰ�еĺ������
                A��'a'����
                c�޸ĵ�ǰ�У��滻��ѯ�ı�
                dɾ��һ�л����
                e����һ���ļ����ǵ�ǰ�ļ�
                E��'e'���ƣ���ֻ���ļ������޸�֮����Ч
                f��ʾ/�ı䵱ǰ�ļ����ļ���
                g��������ƥ�����ִ��ĳ������
                h����
                i�ڵ�ǰ��ǰ�����ַ�
                k��һ���ַ���ǵ�ǰ��
                l�г�һ�л���У��������ַ���
                m�ƶ�һ�л���е�ָ����λ�ã��кţ�
                n����к�
                Oͬ'i'
                oͬ 'a'
                p�г�һ����Χ����
                q�˳�
                Q�˳������Ҳ���
                r���ļ�β����ָ���к���������ļ�
                s�������滻
                set��ѯ���ı��洢ĳ���趨ѡ��
                t����һ�л��е�ָ������
                v�������Բ�ƥ�����ִ��ĳ������
                x���ļ����˳�
                wд�뵱ǰ�ļ�����ָ���ļ������ø���
                W��'w'���ƣ�����׷��
                z��ʾ20�У����� . + - ���ֱ��
                Z��ʾ40�У����� . + - ���ֱ��

HELP
    );
    return 1;
}
