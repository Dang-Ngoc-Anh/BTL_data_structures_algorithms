#include <bits/stdc++.h>
using namespace std;
///                                         TÁC GIẢ                                                 ///
struct Tacgia
{
    int maTG;
    string tenTG;
    int ngay, thang, nam;
    string tieusu;
};
struct NodeTG
{
    Tacgia data;
    struct NodeTG *TGleft;
    struct NodeTG *TGright;
};
typedef NodeTG TG;
typedef TG *treeTG;
void khoitaoTG(treeTG &x)
{
    x = NULL;
}
void themTG(treeTG &x, Tacgia a)
{
    if (x == NULL)
    {
        TG *p = new TG;
        p->data = a;
        p->TGleft = NULL;
        p->TGright = NULL;
        x = p;
    }
    else
    {
        if (x->data.maTG > a.maTG)
        {
            themTG(x->TGleft, a);
        }
        else if (x->data.maTG < a.maTG)
        {
            themTG(x->TGright, a);
        }
    }
}
void nhapTG(Tacgia &x)
{
    cout << "\nNhap ma tac gia: ";
    cin >> x.maTG;
    fflush(stdin);
    cout << "\nNhap Ten tac gia: ";
    getline(cin, x.tenTG);
    fflush(stdin);
    while (true)
    {
        cout << "\nNhap ngay sinh : ";
        cin >> x.ngay;
        cout << "\nNhap Thang sinh : ";
        cin >> x.thang;
        cout << "\nNhap nam sinh : ";
        cin >> x.nam;
        if (x.thang > 0 && x.thang <= 12 && x.ngay > 0 && x.ngay <= 31 && x.nam >= 0)
        {
            break;
        }
        else
        {
            cout << "\nBan nhap sai!!!!";
        }
    }
    fflush(stdin);
    cout << "\n Mot chut tieu su ve tac gia : \n";
    getline(cin, x.tieusu);
}
void hienTG(Tacgia x)
{
    cout << "MA TAC GIA" << setw(21) << "TEN TAC GIA" << setw(21) << "NGAY SINH" << endl;
    cout << setw(10) << x.maTG << setw(19) << x.tenTG << setw(19) << x.ngay << "/" << x.thang << "/" << x.nam << "\nMot chut ve tac gia:  \n\t" << x.tieusu << endl;
}
void NhapDSTG(treeTG &x)
{
    while (true)
    {
        cout << "\n----------------------MENU NHAP SACH----------------------";
        cout << "\n1.Nhap them 1 Tac Gia                                     ";
        cout << "\n0.Ket thuc                                                ";
        cout << "\n----------------------------------------------------------";
        int chon;
        cout << "\nNhap su lua chon: ";
        cin >> chon;
        while (chon < 0 || chon > 1)
        {
            cout << "lua chon khong hop le!!!!Hay chon lai: ";
            cin >> chon;
        }
        if (chon == 1)
        {
            Tacgia a;
            nhapTG(a);
            // hienTG(a);
            themTG(x, a);
        }
        else
            break;
    }
}
void hienDSTG_LNR(treeTG x)
{
    if (x != NULL)
    {
        hienDSTG_LNR(x->TGleft);
        hienTG(x->data);
        hienDSTG_LNR(x->TGright);
    }
}
/// Phần lý thuyết của cây
void node2child(treeTG t)
{
    if (t != NULL)
    {
        if (t->TGleft != NULL && t->TGright != NULL)
        {
            Tacgia x = t->data;
            hienTG(x);
        }
        node2child(t->TGleft);
        node2child(t->TGright);
    }
}
void node1child(treeTG t)
{
    if (t != NULL)
    {
        if ((t->TGleft != NULL && t->TGright == NULL) || (t->TGleft == NULL && t->TGright != NULL))
        {
            Tacgia x = t->data;
            hienTG(x);
        }
        node1child(t->TGleft);
        node1child(t->TGright);
    }
}
void nodela(treeTG t)
{
    if (t != NULL)
    {
        if (t->TGleft == NULL && t->TGright == NULL)
        {
            Tacgia x = t->data;
            hienTG(x);
        }
        nodela(t->TGleft);
        nodela(t->TGright);
    }
}
int baccay(treeTG t)
{
    if (t == NULL)
        return -1;
    return 1 + max(baccay(t->TGleft), baccay(t->TGright));
}

NodeTG *TimTG(treeTG t, int maTG)
{
    NodeTG *p = t;
    while (p != NULL)
    {
        if (maTG == (p->data.maTG))
        {
            return p;
        }
        else if (maTG < (p->data.maTG))
        {
            p = p->TGleft;
        }
        else
        {
            p = p->TGright;
        }
    }
    return NULL;
}
void timTG(treeTG x, int a)
{
    fflush(stdin);

    NodeTG *p;

    p = TimTG(x, a);
    cout << "MA TAC GIA" << setw(21) << "TEN TAC GIA" << setw(21) << "NGAY SINH" << endl;
    hienTG(p->data);
}
//
void timtentacgia(treeTG x, string a)
{
    if (x != NULL)
    {
        if (a == x->data.tenTG)
        {
            hienTG(x->data);
        }
        timtentacgia(x->TGleft, a);
        timtentacgia(x->TGright, a);
    }
}
int SoluongTacgia(treeTG x, int &dem)
{
    if (x != NULL)
    {
        dem = dem + 1;
        SoluongTacgia(x->TGleft, dem);
        SoluongTacgia(x->TGright, dem);
    }
    return dem;
}
int MAX = INT_MIN; // gán gia tri max= nhỏ nhất của int;
int matacgiamax(treeTG t)
{
    if (t != NULL)
    {
        if (MAX < t->data.maTG)
        {
            MAX = t->data.maTG;
        }
        matacgiamax(t->TGleft);
        matacgiamax(t->TGright);
    }
    return MAX;
}

void timmalonnhat(treeTG t)
{
    if (t != NULL)
    {
        int mamax = matacgiamax(t);
        if (mamax == t->data.maTG)
        {
            Tacgia x = t->data;
            hienTG(x);
        }
        timmalonnhat(t->TGleft);
        timmalonnhat(t->TGright);
    }
}
void timnodethaythe(treeTG &p, treeTG &q)
{
    if (q->TGleft)
    {
        timnodethaythe(p, q->TGleft);
    }
    else
    {
        p->data = q->data;
        p = q;
        q = q->TGright;
    }
}

void xoaTG(treeTG &t, int maTG)
{
    if (t == NULL)
    {
        return;
    }
    if (t->data.maTG > maTG)
    {
        return xoaTG(t->TGleft, maTG);
    }
    if (t->data.maTG < maTG)
    {
        return xoaTG(t->TGright, maTG);
    }
    NodeTG *p = t;
    if (t->TGleft == NULL)
    {
        t = t->TGright;
    }
    else if (t->TGright == NULL)
    { // neu cay con phai la rong
        t = t->TGleft;
    }
    else
    { // nguoc lai, neu cay co du 2 con
        timnodethaythe(p, t->TGright);
    }
    // xoa di node p
    delete p;
}
// đẩy vào mảng
void xuat_vao_mangTG(treeTG tree, Tacgia arr[], int &i)
{
    if (tree != NULL)
    {
        xuat_vao_mangTG(tree->TGleft, arr, i);
        arr[i++] = tree->data;
        xuat_vao_mangTG(tree->TGright, arr, i);
    }
}

/*
    sắp xếp cây nhị phân đúng vị trí  , trở thành maxheap , min heap
    max heap : phần tử gốc luôn lớn hơn phần tử con
    min heap : phần tử con luôn lớn hơn phần tử cha
*/
void heapify2(Tacgia a[], int n, int i)
{

    int largest = i;   // vị trí gốc
    int l = 2 * i + 1; // vị trí con trái
    int r = 2 * i + 2; // vị trí con phải

    // value trái hoặc phải lớn hơn gán lại vi trí largest để thằng gốc có value lớn nhất
    if (l < n && a[l].tenTG > a[largest].tenTG)
        largest = l;
    if (r < n && a[r].tenTG > a[largest].tenTG)
        largest = r;

    // hoán đổi để largest có giá trị lớn hơn node con
    if (largest != i)
    {
        swap(a[i], a[largest]);

        // đệ quy đến lúc cây trở thành max heap
        heapify2(a, n, largest);
    }
}
// có max heap đẩy value max vào mảng , thiết lập lại mối liên kết
void heapsort2(Tacgia a[], int n)
{
    // xây dựng lại heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify2(a, n, i);
    }

    // lấy 1 phần tử từ heap
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[i], a[0]);

        // gọi lại max heap thiết lập lại mối liên kết
        heapify2(a, i, 0);
    }
}
// sap xep theo ten
void sapxeptenTG(treeTG cay)
{
    Tacgia a[20];
    int z = 0;
    xuat_vao_mangTG(cay, a, z);
    heapsort2(a, z);
    cout << "MA TAC GIA" << setw(21) << "TEN TAC GIA" << setw(21) << "NGAY SINH" << endl;
    for (int i = 0; i < z; i++)
    {
        Tacgia x = a[i];
        hienTG(x);
    }
}

// sua thong tin tác gia
void suathongtintacgia(treeTG &t)
{
    // xoa(t,masach);
    Tacgia s;
    nhapTG(s);
    themTG(t, s);
}
void ghifileTG(Tacgia arr[], int soluong, string tenfile)
{

    ofstream fo;
    fo.open(tenfile, ios ::out);
    fo << soluong << endl;
    int i = 0;
    while (i < soluong)
    {
        fo << arr[i].maTG << "\n"
           << arr[i].tenTG << "\n"
           << arr[i].ngay << "\n"
           << arr[i].thang << "\n"
           << arr[i].nam << "\n"
           << arr[i].tieusu << "\n";
        i++;
    }
    fo.close();
}
void docfileTG(treeTG &t, string tenfile)
{
    khoitaoTG(t);
    ifstream fi;
    fi.open(tenfile, ios::in);
    int n;
    fi >> n;

    for (int i = 0; i < n; i++)
    {
        Tacgia x;
        fi >> x.maTG;
        string s;
        getline(fi, s);
        getline(fi, x.tenTG);
        fi >> x.ngay;
        fi >> x.thang;
        fi >> x.nam;
        string s1;
        getline(fi, s1);
        getline(fi, x.tieusu);

        themTG(t, x);
    }
    hienDSTG_LNR(t);
}

///                                             SÁCH
struct sach
{
    int masach;
    string tensach;
    string tennhaxuatban;
    treeTG TG;
    int soluongban;
    string tintrang;
};
struct Nodesach
{
    sach data;
    struct Nodesach *sleft;
    struct Nodesach *sright;
};
typedef Nodesach NS;
typedef NS *treeS;
void khoitaoS(treeS &x)
{
    x = NULL;
}
void themsach(treeS &x, sach a)
{
    if (x == NULL)
    {
        NS *p = new NS;
        p->data = a;
        p->sleft = NULL;
        p->sright = NULL;
        x = p;
    }   
    else
    {
        if (x->data.masach > a.masach)
        {
            themsach(x->sleft, a);
        }
        else if (x->data.masach < a.masach)
        {
            themsach(x->sright, a);
        }
    }
}
void nhapS(sach &x, treeTG t)
{
    fflush(stdin);
    cout << "\nNhap ma sach: ";
    cin >> x.masach;
    fflush(stdin);
    cout << "\nNhap ten sach: ";
    getline(cin, x.tensach);
    cout << "\nNhap ten nha xuat ban: ";
    getline(cin, x.tennhaxuatban);
    fflush(stdin);
    cout << "\nNhap so luong tac gia cua cuon sach: ";
    int n;
    int i = 1;
    cin >> n;
    khoitaoTG(x.TG);
    while (i <= n)
    {
        int maTG;
        cout << "\nNhap ma tac gia cua cuon sach: ";
        cin >> maTG;
        NodeTG *p = x.TG;
        p = TimTG(t, maTG);
        // hienTG(t->data);
        themTG(x.TG, p->data);
        i++;
    }
    hienDSTG_LNR(x.TG);
    cout << "\nNhap so luong sach: ";
    cin >> x.soluongban;
    fflush(stdin);
    fflush(stdin);
    cout << "\nChon tinh trang sach: ";
    cout << "\n\t1.Moi";
    cout << "\n\t2.Cu";
    int chon;
    cout << "\nMoi ban chon: ";
    cin >> chon;
    while (chon < 1 || chon > 2)
    {
        cout << "\nLua chon khong hop ly!!!Yeu cau chon lai......:";
        cin >> chon;
    }
    if (chon == 1)
    {
        x.tintrang = "Moi";
    }
    else
        x.tintrang = "Cu";
}
void hienS(sach x)
{
    cout << "\n--------------SACH-------------------------\n";
    cout << "MA SACH" << setw(19) << "TEN SACH" << setw(26) << "NHA XB" << setw(21) << "SO LUONG" << setw(21) << "TINH TRANG" << endl;
    cout << x.masach << setw(25) << x.tensach << setw(21) << x.tennhaxuatban << setw(17) << x.soluongban << setw(21) << x.tintrang << endl;
    cout << "\nTac gia cua sach:   \n";
    hienDSTG_LNR(x.TG);
    cout << "----------------------------------------------\n";
}
void NhapDSS(treeS &s, treeTG t)
{
    // khoitaoS(s);
    while (true)
    {
        cout << "\n----------------------MENU NHAP SACH----------------------";
        cout << "\n1.Nhap them 1 sach                                        ";
        cout << "\n0.Ket thuc                                                ";
        cout << "\n----------------------------------------------------------";
        int chon;
        cout << "\nNhap su lua chon: ";
        cin >> chon;
        while (chon < 0 || chon > 1)
        {
            cout << "lua chon khong hop le!!!!Hay chon lai: ";
            cin >> chon;
        }
        if (chon == 1)
        {
            sach x;
            nhapS(x, t);
            //  hienS(x);
            themsach(s, x);
        }
        else
            break;
    }
}
void hienDSS_NLR(treeS x)
{
    if (x != NULL)
    {
        hienS(x->data);
        hienDSS_NLR(x->sleft);
        hienDSS_NLR(x->sright);
    }
}
Nodesach *Timsach(treeS t, int masach)
{
    Nodesach *p = t;
    while (p != NULL)
    {
        if (masach == (p->data.masach))
        {
            return p;
        }
        else if (masach < (p->data.masach))
        {
            p = p->sleft;
        }
        else
        {
            p = p->sright;
        }
    }
    return NULL;
}
void timS(treeS x)
{
    int a;
    cout << "\nNhap ma sach can tim: ";
    cin >> a;
    Nodesach *p;
    p = Timsach(x, a);
    hienS(p->data);
}

int maxma(treeS t)
{
    if (t->sleft == NULL && t->sright == NULL)
    {
        return t->data.masach;
    }
    int mamax = t->data.masach;
    if (t->sleft != NULL)
    {
        int left = maxma(t->sleft);
        if (mamax < left)
        {
            mamax = left;
        }
    }
    if (t->sright != NULL)
    {
        int right = maxma(t->sright);
        if (mamax < right)
        {
            mamax = right;
        }
    }
    return mamax;
}
void timmalonnhat(treeS t)
{
    if (t != NULL)
    {
        int mamax = maxma(t);
        if (mamax == t->data.masach)
        {
            sach x = t->data;
            hienS(x);
        }
        timmalonnhat(t->sleft);
        timmalonnhat(t->sright);
    }
}

/// xoa
void timnodethaytheS(treeS &p, treeS &q)
{
    if (q->sleft)
    {
        timnodethaytheS(p, q->sleft);
    }
    else
    {
        p->data = q->data;
        p = q;
        q = q->sright;
    }
}

void xoaS(treeS &t, int masach)
{
    if (t == NULL)
    {
        return;
    }
    if (t->data.masach > masach)
    {
        return xoaS(t->sleft, masach);
    }
    if (t->data.masach < masach)
    {
        return xoaS(t->sright, masach);
    }
    Nodesach *p = t;
    if (t->sleft == NULL)
    {
        t = t->sright;
    }
    else if (t->sright == NULL)
    { // neu cay con phai la rong
        t = t->sleft;
    }
    else
    { // nguoc lai, neu cay co du 2 con
        timnodethaytheS(p, t->sright);
    }
    // xoa di node p
    delete p;
}
void xuat_vao_mangS(treeS tree, sach arr[], int &i)
{
    if (tree != NULL)
    {
        xuat_vao_mangS(tree->sleft, arr, i);
        arr[i++] = tree->data;
        xuat_vao_mangS(tree->sright, arr, i);
    }
}
void heapifyS(sach a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l].soluongban > a[largest].soluongban)
        largest = l;
    if (r < n && a[r].soluongban > a[largest].soluongban)
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapifyS(a, n, largest);
    }
}

void heapsortS(sach a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyS(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[i], a[0]);
        heapifyS(a, i, 0);
    }
}
// sap xep theo so luong
void sapxepsolgS(treeS cay)
{
    sach a[20];
    int z = 0;
    xuat_vao_mangS(cay, a, z);
    heapsortS(a, z);
    for (int i = 0; i < z; i++)
    {
        sach x = a[i];
        hienS(x);
    }
}
void suathongtinsach(treeS t, treeTG x)
{
    // xoa(t,masach);
    sach s;
    nhapS(s, x);
    themsach(t, s);
}
void ghifiles(sach arr[], int soluong, string tenfile)
{

    ofstream fo;
    fo.open(tenfile, ios ::out);
    fo << soluong << endl;
    int i = 0;
    while (i < soluong)
    {
        Tacgia a[20];
        int z = 0;
        int j = 0;
        xuat_vao_mangTG(arr[i].TG, a, z);
        fo << arr[i].masach << "\n"
           << arr[i].tensach << "\n"
           << arr[i].tennhaxuatban << "\n"
           << arr[i].soluongban << "\n"
           << arr[i].tintrang << "\n"
           << z << "\n";
        while (j < z)
        {
            fo << a[j].maTG << "\n"
               << a[j].tenTG << "\n"
               << a[j].ngay << "\n"
               << a[j].thang << "\n"
               << a[j].nam << "\n"
               << a[j].tieusu << "\n";
            j++;
        }

        i++;
    }
    fo.close();
}
void docfiles(treeS &t, string tenfile)
{
    khoitaoS(t);
    ifstream fi;
    fi.open(tenfile, ios::in);
    int n;
    fi >> n;

    for (int i = 0; i < n; i++)
    {
        sach x;
        fi >> x.masach;
        string s;
        getline(fi, s);
        getline(fi, x.tensach);
        getline(fi, x.tennhaxuatban);
        fi >> x.soluongban;
        string s1;
        getline(fi, s1);
        getline(fi, x.tintrang);
        int z;
        fi >> z;
        khoitaoTG(x.TG);
        // cout<<"so luong: "<<z;
        for (int j = 0; j < z; j++)
        {
            Tacgia a;
            fi >> a.maTG;
            string s2;
            getline(fi, s2);

            getline(fi, a.tenTG);
            fi >> a.ngay;
            fi >> a.thang;
            fi >> a.nam;
            string s3;
            getline(fi, s3);
            getline(fi, a.tieusu);
            themTG(x.TG, a);
        }
        themsach(t, x);
    }
    hienDSS_NLR(t);
}

/// ------------------------------------------NHAN VIEN------------------------------------------------///

struct NhanVien
{
    int maNV;
    string tenNV, diaChi, SDT;
    double luong;
};
struct NodeNV
{
    NhanVien data;
    struct NodeNV *NvLeft;
    struct NodeNV *NvRight;
};

typedef NodeNV NNV;
typedef NNV *treeNV;

void khoiTaoNV(treeNV &x)
{
    x = NULL;
}

void themNV(treeNV &x, NhanVien nv)
{
    if (x == NULL)
    {
        NNV *p = new NNV;
        p->data = nv;
        p->NvLeft = NULL;
        p->NvRight = NULL;
        x = p;
    }
    else
    {
        if (x->data.maNV > nv.maNV)
        {
            themNV(x->NvLeft, nv);
        }
        else if (x->data.maNV < nv.maNV)
        {
            themNV(x->NvRight, nv);
        }
    }
}

void nhapNV(NhanVien &nv)
{
    fflush(stdin);
    cout << "Nhap ma nhan vien: ";
    cin >> nv.maNV;
    fflush(stdin);

    cout << "\nNhap ten nhan vien: ";
    getline(cin, nv.tenNV);

    cout << "\nNhap dia chi: ";
    getline(cin, nv.diaChi);
    fflush(stdin);
    cout << "\nNhap SDT: ";
    getline(cin, nv.SDT);
    fflush(stdin);
    cout << "\nNhap luong: ";
    cin >> nv.luong;
    fflush(stdin);
}

void nhapDSNV(treeNV &x)
{
    while (true)
    {
        cout << "\n----------------------MENU NHAP SACH----------------------";
        cout << "\n1.Nhap them 1 nhan vien                                   ";
        cout << "\n0.Ket thuc                                                ";
        cout << "\n----------------------------------------------------------";
        int chon;
        cout << "\nNhap su lua chon: ";
        cin >> chon;
        while (chon < 0 || chon > 1)
        {
            cout << "lua chon khong hop le!!!!Hay chon lai: ";
            cin >> chon;
        }
        if (chon == 1)
        {
            NhanVien nv;
            nhapNV(nv);
            //  hienS(x);
            themNV(x, nv);
        }
        else
            break;
    }
}

void hienNV(NhanVien x)
{
    cout << "\nMA NGUOI QUAN LY        : " << x.maNV
         << "\nTEN TEN NGUOI QUAN LY   : " << x.tenNV
         << "\nDIA CHI NGUOI QUAN LY   : " << x.diaChi
         << "\nSO DIEN THOAI           : " << x.SDT
         << "\nTIEN LUONG NGUOI QUAN LY: " << x.luong << endl;
}

void hienDSNV_NLR(treeNV x)
{
    if (x != NULL)
    {
        hienNV(x->data);
        hienDSNV_NLR(x->NvLeft);
        hienDSNV_NLR(x->NvRight);
    }
}

// sử dụng node de tìm kiếm
NodeNV *timNVMa(treeNV t, int maNV)
{
    NodeNV *p = t;
    while (p != NULL)
    {
        if (maNV == (p->data.maNV))
        {
            return p;
        }
        else if (maNV < (p->data.maNV))
        {
            p = p->NvLeft;
        }
        else
        {
            p = p->NvRight;
        }
    }
    return NULL;
}

void timNVTheoMa(treeNV t)
{
    int x;
    cout << "Nhap ma can tim: ";
    cin >> x;
    NodeNV *p;
    p = timNVMa(t, x);
    hienNV(p->data);
}

void timtenNV(treeNV x, string a)
{
    if (x != NULL)
    {
        if (a == x->data.tenNV)
        {
            hienNV(x->data);
        }
        timtenNV(x->NvLeft, a);
        timtenNV(x->NvRight, a);
    }
}

int SoluongNV(treeNV x, int &dem)
{
    if (x != NULL)
    {
        dem = dem + 1;
        SoluongNV(x->NvLeft, dem);
        SoluongNV(x->NvRight, dem);
    }
    return dem;
}

double maxLuong(treeNV t)
{
    // tra ve gia tri
    if (t->NvLeft == NULL && t->NvRight == NULL)
    {
        return t->data.luong;
    }
    double Luongmax = t->data.luong;
    if (t->NvLeft != NULL)
    {
        double left = maxLuong(t->NvLeft);
        if (Luongmax < left)
        {
            Luongmax = left;
        }
    }
    if (t->NvRight != NULL)
    {
        double right = maxLuong(t->NvRight);
        if (Luongmax < right)
        {
            Luongmax = right;
        }
    }
    return Luongmax;
}

void timLuongLonNhat(treeNV t)
{
    if (t != NULL)
    {
        double luongMax = maxLuong(t);
        if (luongMax == t->data.luong)
        {
            NhanVien x = t->data;
            hienNV(x);
        }
        timLuongLonNhat(t->NvLeft);
        timLuongLonNhat(t->NvRight);
    }
}

void timNodeThayTheNV(treeNV &p, treeNV &q)
{
    if (q->NvLeft)
    {
        timNodeThayTheNV(p, q->NvLeft);
    }
    else
    {
        p->data = q->data;
        p = q;
        q = q->NvRight;
    }
}

void xoaNV(treeNV &t, int maNV)
{
    if (t == NULL)
    {
        return;
    }
    if (t->data.maNV > maNV)
    {
        return xoaNV(t->NvLeft, maNV);
    }
    if (t->data.maNV < maNV)
    {
        return xoaNV(t->NvRight, maNV);
    }
    NodeNV *p = t;
    if (t->NvLeft == NULL)
    {
        t = t->NvRight;
    }
    else if (t->NvRight == NULL)
    { // neu cay con phai la rong
        t = t->NvLeft;
    }
    else
    { // nguoc lai, neu cay co du 2 con
        timNodeThayTheNV(p, t->NvRight);
    }
    delete p;
}

void xuatVaoMangNV(treeNV tree, NhanVien arr[], int &i)
{
    if (tree != NULL)
    {
        xuatVaoMangNV(tree->NvLeft, arr, i);
        arr[i++] = tree->data;
        xuatVaoMangNV(tree->NvRight, arr, i);
    }
}

void heapifyLuong(NhanVien a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l].luong > a[largest].luong)
        largest = l;
    if (r < n && a[r].luong > a[largest].luong)
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapifyLuong(a, n, largest);
    }
}

void heapsortLuong(NhanVien a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyLuong(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[i], a[0]);
        heapifyLuong(a, i, 0);
    }
}

void sapXepLuong(treeNV cay)
{
    NhanVien a[20];
    int z = 0;
    xuatVaoMangNV(cay, a, z);
    heapsortLuong(a, z);
    for (int i = 0; i < z; i++)
    {
        NhanVien x = a[i];
        hienNV(x);
    }
}

void heapifyTen(NhanVien a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l].tenNV > a[largest].tenNV)
        largest = l;
    if (r < n && a[r].tenNV > a[largest].tenNV)
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapifyTen(a, n, largest);
    }
}

void heapsortTen(NhanVien a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyTen(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[i], a[0]);
        heapifyTen(a, i, 0);
    }
}

void suaThongTinNV(treeNV &t)
{
    // xoa(t,maNV);
    NhanVien nv;
    nhapNV(nv);
    themNV(t, nv);
}

void ghiFileNV(NhanVien arr[], int soluong, string tenfile)
{

    ofstream fo;
    fo.open(tenfile, ios ::out);
    fo << soluong << endl;
    // cout<<soluong;
    // Nodesach*p=t;
    int i = 0;
    while (i < soluong)
    {
        fo << arr[i].maNV << "\n"
           << arr[i].tenNV << "\n"
           << arr[i].diaChi << "\n"
           << arr[i].SDT << "\n"
           << arr[i].luong << "\n";
        i++;
    }
    fo.close();
}
void docFileNV(treeNV &t, string tenfile)
{
    khoiTaoNV(t);
    ifstream fi;
    fi.open(tenfile, ios::in);
    int n;
    fi >> n;
    for (int i = 0; i < n; i++)
    {
        NhanVien x;
        fi >> x.maNV;
        string s;
        getline(fi, s);

        getline(fi, x.tenNV);
        getline(fi, x.diaChi);
        getline(fi, x.SDT);
        fi >> x.luong;
        themNV(t, x);
    }
    hienDSNV_NLR(t);
}

///-------------------------------------------ĐỌC GIẢ----------------------------------------------///
struct DocGia
{
    int maDG;
    string tenDG, diaChi, SDT;
    int TienPhatDaNop;
};
struct NodeDG
{
    DocGia data;
    struct NodeDG *DgLeft;
    struct NodeDG *DgRight;
};

typedef NodeDG NDG;
typedef NDG *treeDG;

void khoiTaoDG(treeDG &x)
{
    x = NULL;
}

void themDG(treeDG &x, DocGia kh)
{
    if (x == NULL)
    {
        NDG *p = new NDG;
        p->data = kh;
        p->DgLeft = NULL;
        p->DgRight = NULL;
        x = p;
    }
    else
    {
        if (x->data.maDG > kh.maDG)
        {
            themDG(x->DgLeft, kh);
        }
        else if (x->data.maDG < kh.maDG)
        {
            themDG(x->DgRight, kh);
        }
    }
}


//them cay quan ly dua tren tong tien phat da nop 


void themDGDuaTrenTienPhat(treeDG &x, DocGia kh)
{
    if (x == NULL)
    {
        NDG *p = new NDG;
        p->data = kh;
        p->DgLeft = NULL;
        p->DgRight = NULL;
        x = p;
    }
    else
    {
        if (x->data.TienPhatDaNop > kh.TienPhatDaNop)
        {
            themDG(x->DgLeft, kh);
        }
        else if (x->data.TienPhatDaNop < kh.TienPhatDaNop)
        {
            themDG(x->DgRight, kh);
        }
    }
}

void nhapDG(DocGia &dg)
{
    fflush(stdin);
    cout << "Nhap ma khach hang: ";
    cin >> dg.maDG;
    fflush(stdin);

    cout << "\nNhap ten khach hang: ";
    getline(cin, dg.tenDG);

    cout << "\nNhap dia chi: ";
    getline(cin, dg.diaChi);
    fflush(stdin);
    cout << "\nNhap SDT: ";
    getline(cin, dg.SDT);
    fflush(stdin);
    cout << "Nhap Tien Phat Da Nop : " ;
    cin >> dg.TienPhatDaNop;
}

void nhapDSDG(treeDG &x)
{
    while (true)
    {
        cout << "\n----------------------MENU NHAP SACH----------------------";
        cout << "\n1.Nhap them 1 khach hang                                  ";
        cout << "\n0.Ket thuc                                                ";
        cout << "\n----------------------------------------------------------";
        int chon;
        cout << "\nNhap su lua chon: ";
        cin >> chon;
        while (chon < 0 || chon > 1)
        {
            cout << "lua chon khong hop le!!!!Hay chon lai: ";
            cin >> chon;
        }
        if (chon == 1)
        {
            DocGia dg;
            nhapDG(dg);
            themDG(x, dg);
        }
        else
            break;
    }
}


// DS Doc Gia qua ly theo tong tien phat

void nhapDSDGTheoTongTienPhat(treeDG &x)
{
    while (true)
    {
        cout << "\n----------------------MENU NHAP SACH----------------------";
        cout << "\n1.Nhap them 1 khach hang                                  ";
        cout << "\n0.Ket thuc                                                ";
        cout << "\n----------------------------------------------------------";
        int chon;
        cout << "\nNhap su lua chon: ";
        cin >> chon;
        while (chon < 0 || chon > 1)
        {
            cout << "lua chon khong hop le!!!!Hay chon lai: ";
            cin >> chon;
        }
        if (chon == 1)
        {
            DocGia dg;
            nhapDG(dg);
            themDGDuaTrenTienPhat(x, dg);
        }
        else
            break;
    }
}
void hienDG(DocGia x)
{
    cout << "\n\tMa Doc Gia           : " << x.maDG
         << "\n\tTen Doc Gia          : " << x.tenDG
         << "\n\tDia chi Doc Gia      : " << x.diaChi
         << "\n\tSo Dien Thoai Doc Gia: " << x.SDT 
         << "\n\tTien Phat Da Nop     : "  << x.TienPhatDaNop << endl;
}

void hienDSDG_NLR(treeDG x)
{
    if (x != NULL)
    {
        hienDG(x->data);
        hienDSDG_NLR(x->DgLeft);
        hienDSDG_NLR(x->DgRight);
    }
}

NodeDG *timDGMa(treeDG t, int maDG)
{
    NodeDG *p = t;
    while (p != NULL)
    {
        if (maDG == (p->data.maDG))
        {
            return p;
        }
        else if (maDG < (p->data.maDG))
        {
            p = p->DgLeft;
        }
        else
        {
            p = p->DgRight;
        }
    }
    return NULL;
}

NodeDG *timDGTen(treeDG t, string ten)
{
    NodeDG *p = t;
    while (p != NULL)
    {
        if (ten == (p->data.tenDG))
        {
            return p;
        }
        else if (ten < (p->data.tenDG))
        {
            p = p->DgLeft;
        }
        else
        {
            p = p->DgRight;
        }
    }
    return NULL;
}
void timDGTheoMa(treeDG t)
{
    int x;
    cout << "Nhap ma can tim: ";
    cin >> x;
    NodeDG *p;
    p = timDGMa(t, x);
    hienDG(p->data);
}

void timtenDocgia(treeDG x, string a)
{
    if (x != NULL)
    {
        if (a == x->data.tenDG)
        {
            hienDG(x->data);
        }
        timtenDocgia(x->DgLeft, a);
        timtenDocgia(x->DgRight, a);
    }
}

int SoluongDG(treeDG x, int &dem)
{
    if (x != NULL)
    {
        dem = dem + 1;
        SoluongDG(x->DgLeft, dem);
        SoluongDG(x->DgRight, dem);
    }
    return dem;
}

void timNodeThayTheDG(treeDG &p, treeDG &q)
{
    if (q->DgLeft)
    {
        timNodeThayTheDG(p, q->DgLeft);
    }
    else
    {
        p->data = q->data;
        p = q;
        q = q->DgRight;
    }
}

void xoaDG(treeDG &t, int maDG)
{
    if (t == NULL)
    {
        return;
    }
    if (t->data.maDG > maDG)
    {
        return xoaDG(t->DgLeft, maDG);
    }
    if (t->data.maDG < maDG)
    {
        return xoaDG(t->DgRight, maDG);
    }
    NodeDG *p = t;
    if (t->DgLeft == NULL)
    {
        t = t->DgRight;
    }
    else if (t->DgRight == NULL)
    { // neu cay con phai la rong
        t = t->DgLeft;
    }
    else
    { // nguoc lai, neu cay co du 2 con
        timNodeThayTheDG(p, t->DgRight);
    }
    delete p;
}

void xuatVaoMangDG(treeDG tree, DocGia arr[], int &i)
{
    if (tree != NULL)
    {
        xuatVaoMangDG(tree->DgLeft, arr, i);
        arr[i++] = tree->data;
        xuatVaoMangDG(tree->DgRight, arr, i);
    }
}

void heapifyTenDG(DocGia a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l].tenDG > a[largest].tenDG)
        largest = l;
    if (r < n && a[r].tenDG > a[largest].tenDG)
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapifyTenDG(a, n, largest);
    }
}

void heapsortTenDG(DocGia a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyTenDG(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[i], a[0]);
        heapifyTenDG(a, i, 0);
    }
}

void sapXepTenDG(treeDG cay)
{
    DocGia a[20];
    int z = 0;
    xuatVaoMangDG(cay, a, z);
    heapsortTenDG(a, z);
    for (int i = 0; i < z; i++)
    {
        DocGia x = a[i];
        hienDG(x);
    }
}

void suaThongTinDG(treeDG &t)
{
    // xoa(t,maNV);
    DocGia dg;
    nhapDG(dg);
    themDG(t, dg);
}

void ghiFileDG(DocGia arr[], int soluong, string tenfile)
{

    ofstream fo;
    fo.open(tenfile, ios ::out);
    fo << soluong << endl;
    // cout<<soluong;
    // Nodesach*p=t;
    int i = 0;
    while (i < soluong)
    {
        fo << arr[i].maDG << "\n"
           << arr[i].tenDG << "\n"
           << arr[i].diaChi << "\n"
           << arr[i].SDT << "\n"
           << arr[i].TienPhatDaNop << "\n";
        i++;
    }
    fo.close();
}

void docFileDG(treeDG &t, string tenfile)
{
    khoiTaoDG(t);
    ifstream fi;
    fi.open(tenfile, ios::in);
    int n;
    fi >> n;
    for (int i = 0; i < n; i++)
    {
        DocGia x;
        fi >> x.maDG;
        string s;
        getline(fi, s);

        getline(fi, x.tenDG);
        getline(fi, x.diaChi);
        getline(fi, x.SDT);
        fi >> x.TienPhatDaNop;
        themDG(t, x);
    }
    hienDSDG_NLR(t);
}
///---------------------------------------------------------Phieu muon------------------------------------///
struct Phieu
{
    int maPhieu;
    NhanVien NhanVien;
    DocGia DocGia;
    treeS sach;
    int songaymuon;
};
struct NodePhieu
{
    Phieu data;
    struct NodePhieu *Pleft;
    struct NodePhieu *Pright;
};
typedef NodePhieu NP;
typedef NP *treeP;
void khoitaoP(treeP &x)
{
    x = NULL;
}
void themphieu(treeP &x, Phieu a)
{
    if (x == NULL)
    {
        NP *p = new NP;
        p->data = a;
        p->Pleft = NULL;
        p->Pright = NULL;
        x = p;
    }
    else
    {
        if (x->data.maPhieu > a.maPhieu)
        {
            themphieu(x->Pleft, a);
        }
        else if (x->data.maPhieu < a.maPhieu)
        {
            themphieu(x->Pright, a);
        }
    }
}
void NhapP(Phieu &a, treeDG z, treeNV x, treeS c)
{
    int nv, dg, n;
    fflush(stdin);
    cout << "\nNhap ma phieu muon tra: ";
    cin >> a.maPhieu;
    cout << "\nNhap ma nhan vien: ";
    cin >> nv;
    NodeNV *k = timNVMa(x, nv);
    hienNV(k->data);
    a.NhanVien = k->data;
    fflush(stdin);
    cout << "\nNhap ma nguoi muon: ";
    cin >> dg;
    NodeDG *j = timDGMa(z, dg);
    hienDG(j->data);
    a.DocGia = z->data;
    fflush(stdin);
    cout << "\nNhap so sach muon: ";
    cin >> n;

    khoitaoS(a.sach);
    for (int i = 0; i < n; i++)
    {
        int s;
        cout << "\nNhap ma sach: ";
        cin >> s;
        Nodesach *l = Timsach(c, s);
        themsach(a.sach, l->data);
    }
    hienDSS_NLR(a.sach);
    cout << "\nNhap so ngay muon:";
    cin >> a.songaymuon;
    fflush(stdin);
}
void hienP(Phieu a)
{
    cout << "\n-----------------------------PHIEU----------------------------------";
    cout << "\n"
         << setw(19) << "MA PHIEU" << setw(19) << "SO NGAY MUON";
    cout << "\n"
         << setw(12) << a.maPhieu << setw(10) << a.songaymuon << endl;
    cout << "\nThong tin nguoi quan ly phieu\n";
    hienNV(a.NhanVien);
    cout << "\n\tThong tin Doc gia muon \n";
    hienDG(a.DocGia);
    cout << "THONG TIN SACH MUON" << endl;
    hienDSS_NLR(a.sach);
}
void NhapDSP(treeP &p, treeDG z, treeNV x, treeS c)
{
    while (true)
    {
        cout << "\n----------------------MENU PHIEU MUON ----------------------";
        cout << "\n1.Tao 1 phieu muon                                        ";
        cout << "\n0.Ket thuc                                                ";
        cout << "\n----------------------------------------------------------";
        int chon;
        cout << "\nNhap su lua chon: ";
        cin >> chon;
        while (chon < 0 || chon > 1)
        {
            cout << "lua chon khong hop le!!!!Hay chon lai: ";
            cin >> chon;
        }
        if (chon == 1)
        {
            Phieu a;
            NhapP(a, z, x, c);
            hienP(a);
            themphieu(p, a);
            fflush(stdin);
        }
        else
            break;
    }
}
void hienphieu(treeP x)
{
    if (x != NULL)
    {
        hienP(x->data);
        hienphieu(x->Pleft);
        hienphieu(x->Pright);
    }
}
void Timphieu(treeP x, string tendocG)
{
    if (x != NULL)
    {
        if (x->data.DocGia.tenDG == tendocG)
        {
            hienP(x->data);
        }
        Timphieu(x->Pleft, tendocG);
        Timphieu(x->Pright, tendocG);
    }
}
void xuatVaoMangP(treeP tree, Phieu arr[], int &i)
{
    if (tree != NULL)
    {
        xuatVaoMangP(tree->Pleft, arr, i);
        arr[i++] = tree->data;
        xuatVaoMangP(tree->Pright, arr, i);
    }
}
void ghiFileP(Phieu arr[], int soluong, string tenfile)
{
    ofstream fo;
    fo.open(tenfile, ios ::out);
    fo << soluong << endl;
    int i = 0;
    while (i < soluong)
    {
        sach a[20];
        int soluongsachcuaphieu = 0;
        int j = 0;
        xuat_vao_mangS(arr[i].sach, a, soluongsachcuaphieu);
        fo << arr[i].maPhieu << "\n"
           << arr[i].songaymuon << "\n"
           << arr[i].NhanVien.maNV << "\n"
           << arr[i].NhanVien.tenNV << "\n"
           << arr[i].NhanVien.SDT << "\n"
           << arr[i].NhanVien.diaChi << "\n"
           << arr[i].NhanVien.luong << "\n"
           << arr[i].DocGia.maDG << "\n"
           << arr[i].DocGia.tenDG << "\n"
           << arr[i].DocGia.SDT << "\n"
           << arr[i].DocGia.diaChi << "\n"
           << soluongsachcuaphieu << "\n";
        while (j < soluongsachcuaphieu)
        {
            Tacgia b[20];
            int soluongtacgiasachcuaphieu = 0;
            int z = 0;
            xuat_vao_mangTG(arr[i].sach->data.TG, b, soluongtacgiasachcuaphieu);
            fo << a[j].masach << "\n"
               << a[j].tensach << "\n"
               << a[j].tennhaxuatban << "\n"
               << a[j].soluongban << "\n"
               << a[j].tintrang << "\n"
               << soluongtacgiasachcuaphieu << "\n";
            while (z < soluongtacgiasachcuaphieu)
            {
                fo << b[z].maTG << "\n"
                   << b[z].tenTG << "\n"
                   << b[z].ngay << "\n"
                   << b[z].thang << "\n"
                   << b[z].nam << "\n"
                   << b[z].tieusu << "\n";
                z++;
            }
            j++;
        }
        i++;
    }
}
void docfileP(treeP &t, string tenfile)
{
    khoitaoP(t);
    ifstream fi;
    fi.open(tenfile, ios::in);
    int n;
    fi >> n;
    for (int i = 0; i < n; i++)
    {
        Phieu x;
        fi >> x.maPhieu;
        fi >> x.songaymuon;
        fi >> x.NhanVien.maNV;
        string s;
        getline(fi, s);
        getline(fi, x.NhanVien.tenNV);
        getline(fi, x.NhanVien.SDT);
        getline(fi, x.NhanVien.diaChi);
        fi >> x.NhanVien.luong;
        fi >> x.DocGia.maDG;
        string s1;
        getline(fi, s1);
        getline(fi, x.DocGia.tenDG);
        getline(fi, x.DocGia.SDT);
        getline(fi, x.DocGia.diaChi);
        int soluongsachphieu;
        fi >> soluongsachphieu;
        khoitaoS(x.sach);
        for (int j = 0; j < soluongsachphieu; j++)
        {
            sach y;
            fi >> y.masach;
            string s2;
            getline(fi, s2);
            getline(fi, y.tensach);
            getline(fi, y.tennhaxuatban);
            fi >> y.soluongban;
            string s3;
            getline(fi, s3);
            getline(fi, y.tintrang);
            int soluongTGcuasachphieu;
            fi >> soluongTGcuasachphieu;
            khoitaoTG(y.TG);
            for (int z = 0; z < soluongTGcuasachphieu; z++)
            {
                Tacgia k;
                fi >> k.maTG;
                string s4;
                getline(fi, s4);
                getline(fi, k.tenTG);
                fi >> k.ngay;
                fi >> k.thang;
                fi >> k.nam;
                string s5;
                getline(fi, s5);
                getline(fi, k.tieusu);
                themTG(y.TG, k);
            }
            themsach(x.sach, y);
        }
        themphieu(t, x);
    }
    hienphieu(t);
}

void menuQLTG()
{
    cout << "\n\t||--------------------Quan ly Tac Gia-------------------------||" << endl;
    cout << "\t||1 .Nhap danh sach tac gia                                   ||" << endl;
    cout << "\t||2 .Hien danh sach tac gia                                   ||" << endl;
    cout << "\t||3 .Quan ly cay                                              ||" << endl;
    cout << "\t||4 .Tim Tac gia theo ten                                     ||" << endl;
    cout << "\t||5 .So luong tac gia                                         ||" << endl;
    cout << "\t||6 .Sap xep tac gia theo ten                                 ||" << endl;
    cout << "\t||7 .Xoa tac gia theo ma                                      ||" << endl;
    cout << "\t||8 .Sua tac gia                                              ||" << endl;
    cout << "\t||9 .Ghi file Tac gia                                         ||" << endl;
    cout << "\t||10.Doc file Tac gia                                         ||" << endl;
    cout << "\t||0 .Ve menu chinh                                            ||" << endl;
    cout << "\t||------------------------------------------------------------||" << endl;
}
void menuquanlycayTG()
{
    cout << "\n||----------------Cay TG--------------------||";
    cout << "\n||1.Node 1 con                              ||";
    cout << "\n||2.Node 2 con                              ||";
    cout << "\n||3.Node la                                 ||";
    cout << "\n||4.Bac cua cay                             ||";
    cout << "\n||0.Ve quan ly Tac gia                      ||";
    cout << "\n--------------------------------------------||";
}
void menuquanlysach()
{
    cout << "\n\t||--------------------Quan ly sach-------------------------||";
    cout << "\n\t||1 .Nhap sach cua thu vien                                ||";
    cout << "\n\t||2 .Hien sach cua thu vien                                ||";
    cout << "\n\t||3 .Tim sach cua thu vien theo ma                         ||";
    cout << "\n\t||4 .Tim ma cua sach lon nhat                              ||";
    cout << "\n\t||5 .Sap xep sach theo so luong co cua thu vien            ||";
    cout << "\n\t||6 .xoa sach theo ma                                      ||";
    cout << "\n\t||7 .Sua thong tin sach cua thu vien                       ||";
    cout << "\n\t||8 .Ghi file sach cho thu vien                            ||";
    cout << "\n\t||9 .Doc file sach cho thu vien                            ||";
    cout << "\n\t||0 .Quan ve menu chinh                                    ||";
    cout << "\n\t||---------------------------------------------------------||";
}
void menuquanlynguoicoitv()
{
    cout << "\n\t||---------------------Quan ly nguoi quan ly thu vien-----------------||";
    cout << "\n\t||1 .Nhap nguoi quan ly                                               ||";
    cout << "\n\t||2 .Hien nguoi quan ly                                               ||";
    cout << "\n\t||3 .Tim nguoi quan ly theo ten                                       ||";
    cout << "\n\t||4 .Dem so luong nguoi quan ly                                       ||";
    cout << "\n\t||5 .Tim nguoi quan ly co luong nhat                                  ||";
    cout << "\n\t||6 .Sap xep nguoi quan ly                                            ||";
    cout << "\n\t||7 .Xoa nguoi quan ly                                                ||";
    cout << "\n\t||8 .Sua nguoi quan ly                                                ||";
    cout << "\n\t||9 .Ghi file nguoi quan ly                                           ||";
    cout << "\n\t||10.Doc file nguoi quan ly                                           ||";
    cout << "\n\t||0 .Ve menu chinh                                                    ||";
    cout << "\n\t||--------------------------------------------------------------------||";
}
void menuquanlyDocgia()
{
    cout << "\n\t||--------------------Quan ly doc gia---------------------------||";
    cout << "\n\t||1 .Nhap Doc gia                                               ||";
    cout << "\n\t||2 .Hien Doc gia                                               ||";
    cout << "\n\t||3 .Tim Doc gia  theo ma                                       ||";
    cout << "\n\t||4 .Dem so luong doc gia                                       ||";
    cout << "\n\t||5 .Sap xep doc gia                                            ||";
    cout << "\n\t||6 .xoa Doc gia                                                ||";
    cout << "\n\t||7 .Sua Doc gia                                                ||";
    cout << "\n\t||8 .Ghi file doc gia                                           ||";
    cout << "\n\t||9 .Doc file doc gia                                           ||";
    cout << "\n\t||10.Nhap Doc Gia Qua ly Theo Tong tien Phat                    ||"; 
    cout << "\n\t||0 .Ve menu chinh                                              ||";
    cout << "\n\t||--------------------------------------------------------------||";
}
void menuQuanlyphieumuontra()
{
    cout << "\n\t||-----------------Quan ly phieu muon tra-----------------------||";
    cout << "\n\t||1 .Nhap phieu muon tra                                        ||";
    cout << "\n\t||2 .Hien phieu muon tra                                        ||";
    cout << "\n\t||3 .Tim phieu theo ten doc gia                                 ||";
    cout << "\n\t||4 .Ghi file phieu muon tra                                    ||";
    cout << "\n\t||5 .Doc file phieu muong tra                                   ||";
    cout << "\n\t||0 .Ve menu chinh                                              ||";
    cout << "\n\t||--------------------------------------------------------------||";
}
void menuDocfile()
{
    cout << "\n\t||----------------Doc file------------------------||";
    cout << "\n\t||1 .Doc file Tacgia.txt                          ||";
    cout << "\n\t||2 .Doc file Sach.txt                            ||";
    cout << "\n\t||3 .Doc file Docgia.txt                          ||";
    cout << "\n\t||4 .Doc file Nguoiquanly.txt                     ||";
    cout << "\n\t||5 .Doc file Phieu.txt                           ||";
    cout << "\n\t||0 .Ve menu chinh                                ||";
    cout << "\n\t||------------------------------------------------||";
}
void menuQuanlythuvien()
{
    cout << "\n\t\t\t||---------------------QUAN LY THU VIEN-----------------------||";
    cout << "\n\t\t\t||1 .Quan ly Tac gia                                          ||";
    cout << "\n\t\t\t||2 .Quan ly Sach                                             ||";
    cout << "\n\t\t\t||3 .Quan ly Doc Gia                                          ||";
    cout << "\n\t\t\t||4 .Quan ly Nguoi quan ly thu vien                           ||";
    cout << "\n\t\t\t||5 .Quan ly Thu vien (Thong tin luu hanh sach)               ||";
    cout << "\n\t\t\t||6 .Doc file da luu                                          ||";
    cout << "\n\t\t\t||0 .Ket thuc chuong trinh                                    ||";
    cout << "\n\t\t\t||-------------------------END--------------------------------||";
}
int main()
{
    treeTG cayTG;
    khoitaoTG(cayTG);

    treeS cayS;
    khoitaoS(cayS);

    treeNV cayNV;
    khoiTaoNV(cayNV);

    treeDG cayDG;
    khoiTaoDG(cayDG);

    treeP cayP;
    khoitaoP(cayP);

    int chon, chon1, chon2, chon3;
    int demTG = 0;
    int demNV = 0;
    int demDG = 0;
    // docFileDG(cayDG , "Docgia.txt");
    // NodeDG * p = timDGMa(cayDG , 2) ;
    // NodeDG * p1 = timDGTen(cayDG , "Ngoc Anh") ;
    // cout << "sdhvgf" << endl  << p ->data.tenDG<< endl;
    // cout <<  p1 ->data.tenDG;
    
    do
    {
        menuQuanlythuvien();
        cout << "\nMoi ban chon lua chon: ";
        cin >> chon;
        switch (chon)
        {
        case 1:
            do
            {
                menuQLTG();
                cout << "\nMoi ban chon lua chon: ";
                cin >> chon1;
                switch (chon1)
                {
                case 1:
                    NhapDSTG(cayTG);
                    break;
                case 2:
                    hienDSTG_LNR(cayTG);
                    break;
                case 3:
                    do
                    {
                        menuquanlycayTG();
                        cout << "\nMoi ban chon cach quan ly: ";
                        cin >> chon3;
                        switch (chon3)
                        {
                        case 1:
                            node1child(cayTG);
                            break;
                        case 2:
                            node2child(cayTG);
                            break;
                        case 3:
                            nodela(cayTG);
                            break;
                        case 4:
                            cout << "\nBac cua cay la : " << baccay(cayTG);
                            break;
                        case 0:
                            break;
                        default:
                            cout << "\nBan chon sai. Moi ban chon lai !" << endl;
                        }
                        system("pause");
                        system("cls");
                    } while (chon3 != 0);
                    break;
                case 4:
                {
                    string x;
                    cout << "\nNhap ten tac gia can tim: ";
                    fflush(stdin);
                    getline(cin , x);
                    cout << "\nThong tin tac gia can tim la: ";
                    timtentacgia(cayTG, x);
                    break;
                }
                case 5:
                    cout << "\nSo luong tac gia o trong cay la: " << SoluongTacgia(cayTG, demTG);
                    break;
                case 6:
                    cout << "\nDanh sach duoc sap xep theo ten la: ";
                    sapxeptenTG(cayTG);
                    break;
                case 7:
                {
                    int a;
                    cout << "\nNhap ma Tac gia can xoa: ";
                    cin >> a;
                    xoaTG(cayTG, a);
                    break;
                }
                case 8:
                {
                    int a;
                    cout << "\nNhap ma can sua ";
                    cin >> a;
                    xoaTG(cayTG, a);
                    suathongtintacgia(cayTG);
                    break;
                }
                case 9:
                {
                    int z = 0;
                    Tacgia TG[100];
                    string tenfile;
                    cout << "\nNhap ten file de ghi: ";
                    cin >> tenfile;
                    xuat_vao_mangTG(cayTG, TG, z);
                    ghifileTG(TG, z, tenfile);
                    cout << "\nDa ghi thanh cong vao file : " << tenfile << endl;
                    break;
                }
                case 10:
                {
                    string tenfile;
                    cout << "\nNhap ten file de doc:  ";
                    cin >> tenfile;
                    cout << "\nDoc file " << tenfile << " thanh cong!!!!!!" << endl;
                    docfileTG(cayTG, tenfile);
                    break;
                }

                case 0:
                    break;
                default:
                    cout << "\nBan chon sai. Moi ban chon lai !" << endl;
                }
                system("pause");
                system("cls");
            } while (chon1 != 0);

            break;
        case 2:
            do
            {
                menuquanlysach();
                cout << "\nMoi ban chon: ";
                cin >> chon2;
                switch (chon2)
                {
                case 1:
                    NhapDSS(cayS, cayTG);
                    break;
                case 2:
                    hienDSS_NLR(cayS);
                    break;
                case 3:
                    timS(cayS);
                    break;
                case 4:
                    timmalonnhat(cayS);
                    break;
                case 5:
                    sapxepsolgS(cayS);
                    break;
                case 6:
                {
                    int masach;
                    cout << "\nNhap ma sach can xoa : ";
                    cin >> masach;
                    xoaS(cayS, masach);
                    break;
                }
                case 7:
                {
                    int masach;
                    cout << "\nNhap ma sach can sua : ";
                    cin >> masach;
                    xoaS(cayS, masach);
                    suathongtinsach(cayS, cayTG);
                    break;
                }
                case 8:
                {
                    int z = 0;
                    sach S[100];
                    string tenfile;
                    cout << "\nNhap ten file ghi : ";
                    cin >> tenfile;
                    xuat_vao_mangS(cayS, S, z);
                    ghifiles(S, z, tenfile);
                    cout << "\nDa ghi thanh cong file " << tenfile;
                    break;
                }
                case 9:
                {
                    string tenfile;
                    cout << "\nNhap ten file de doc:  ";
                    cin >> tenfile;
                    cout << "\nDoc file " << tenfile << " thanh cong!!!!!!" << endl;
                    docfiles(cayS, tenfile);
                    break;
                }
                case 0:
                    break;
                default:
                    cout << "\nBan chon sai. Moi ban chon lai !" << endl;
                }
                system("pause");
                system("cls");
            } while (chon2 != 0);
            break;

        case 3:
            do
            {
                menuquanlyDocgia();
                cout << "\nMoi ban chon su lua chon: ";
                cin >> chon2;
                switch (chon2)
                {
                case 1:
                    nhapDSDG(cayDG);
                    break;
                case 2:
                    cout << "\nThong tin cac doc gia ";
                    hienDSDG_NLR(cayDG);
                    break;
                case 3:
                    timDGTheoMa(cayDG);
                    break;
                case 4:
                cout << "\nSo luong Doc Gia : " <<SoluongDG(cayDG, demDG) << endl; 
                    break;
                case 5:
                    sapXepTenDG(cayDG);
                    break;
                case 6:
                {
                    int ma;
                    cout << "\nNhap ma can xoa: ";
                    cin >> ma;
                    xoaDG(cayDG, ma);
                    break;
                }
                case 7:
                {
                    int ma;
                    cout << "\nNhap ma can sua: ";
                    cin >> ma;
                    xoaDG(cayDG, ma);
                    suaThongTinDG(cayDG);
                    break;
                }
                case 8:
                {
                    int z = 0;
                    DocGia DG[100];
                    string tenfile;
                    cout << "\nNhap ten file can ghi: ";
                    cin >> tenfile;
                    xuatVaoMangDG(cayDG, DG, z);
                    ghiFileDG(DG, z, tenfile);
                    cout << "\nDa ghi thanh cong file : " << tenfile;
                    break;
                }
                case 9:
                {
                    string tenfile;
                    cout << "\nNhap ten file can doc: ";
                    cin >> tenfile;
                    docFileDG(cayDG, tenfile);
                    break;
                }
                case 10 : {
                    nhapDSDGTheoTongTienPhat(cayDG );
                    break;
                }
                case 0:
                    break;
                default:
                    cout << "\nBan chon sai. Moi ban chon lai !" << endl;
                }
                system("pause");
                system("cls");
            } while (chon2 != 0);
            break;
        case 4:
            do
            {
                menuquanlynguoicoitv();
                cout << "\nMoi ban chon chuc nang : ";
                cin >> chon2;
                switch (chon2)
                {
                case 1:
                    nhapDSNV(cayNV);
                    break;
                case 2:
                    hienDSNV_NLR(cayNV);
                    break;
                case 3:
                {
                    string ten;
                    cout << "\nNhap ten nguoi quan ly: ";
                    fflush(stdin);
                    getline(cin , ten) ;
                    timtenNV(cayNV, ten);

                    break;
                }
                case 4:
                    cout << "\nSo nguoi quan ly : " << SoluongNV(cayNV, demNV);
                    break;
                case 5:
                    timLuongLonNhat(cayNV);
                    break;
                case 6:
                    sapXepLuong(cayNV);
                    break;
                case 7:
                {
                    int ma;
                    cout << "\nNhap ma nguoi quan ly can xoa : ";
                    cin >> ma;
                    xoaNV(cayNV, ma);
                    break;
                }
                case 8:
                {
                    int ma;
                    cout << "\nNhap ma nguoi quan ly can sua : ";
                    cin >> ma;
                    xoaNV(cayNV, ma);
                    suaThongTinNV(cayNV);
                    break;
                }
                case 9:
                {
                    int z = 0;
                    NhanVien NV[100];
                    string tenfile;
                    cout << "\nNhap ten file ghi : ";
                    cin >> tenfile;
                    xuatVaoMangNV(cayNV, NV, z);
                    ghiFileNV(NV, z, tenfile);
                    cout << "\nDa ghi thanh cong file " << tenfile;
                    break;
                }
                case 10:
                {
                    string tenfile;
                    cout << "\nNhap ten file de doc:  ";
                    cin >> tenfile;
                    cout << "\nDoc file " << tenfile << " thanh cong!!!!!!" << endl;
                    docFileNV(cayNV, tenfile);
                    break;
                }
                case 0:
                    break;
                default:
                    cout << "\nBan chon sai. Moi ban chon lai !" << endl;
                }
                system("pause");
                system("cls");
            } while (chon2 != 0);

            break;
        case 5:
            do
            {
                menuQuanlyphieumuontra();
                cout << "\nMoi ban chon: ";
                cin >> chon2;
                switch (chon2)
                {
                case 1:
                    NhapDSP(cayP, cayDG, cayNV, cayS);
                    break;
                case 2:
                    hienphieu(cayP);
                    break;
                case 3:
                {
                    string tenDG;
                    cout << "\nNhap ten doc gia can tim phieu: ";
                    cin >> tenDG;
                    Timphieu(cayP, tenDG);
                    break;
                }
                case 4:
                {
                    int z = 0;
                    Phieu P[100];
                    string tenfile;
                    cout << "\nNhap ten file can luu: ";
                    cin >> tenfile;
                    xuatVaoMangP(cayP, P, z);
                    ghiFileP(P, z, tenfile);
                    break;
                }
                case 5:
                {
                    string tenfile;
                    cout << "\nNhap ten file can doc: ";
                    cin >> tenfile;
                    cout << "\nDoc file " << tenfile << " thanh cong";
                    docfileP(cayP, tenfile);
                    break;
                }
                case 0:
                    break;
                default:
                    cout << "\nBan chon sai. Moi ban chon lai !" << endl;
                }
                system("pause");
                system("cls");
            } while (chon2 != 0);
            break;
        case 6 :
            do
            {
                menuDocfile();
                cout << "\nMoi ban chon: ";
                cin >> chon2;
                switch (chon2)
                {
                case 1:
                    docfileTG(cayTG, "Tacgia.txt");
                    break;
                case 2:
                    docfiles(cayS, "Sach.txt");
                    break;
                case 3:
                    docFileDG(cayDG, "Docgia.txt");
                    break;
                case 4:
                    docFileNV(cayNV, "Nguoiquanly.txt");
                    break;
                case 5:
                    docfileP(cayP, "Phieu.txt");
                    break;
                case 0:
                    break;
                default:
                    cout << "\nBan chon sai. Moi ban chon lai !" << endl;
                }
                system("pause");
                system("cls");
            } while (chon2 != 0);

            break;
        case 0:
            break;
        default:
            cout << "\nBan chon sai. Moi ban chon lai !" << endl;
        }
    } while (chon != 0);
    return 0;
}
